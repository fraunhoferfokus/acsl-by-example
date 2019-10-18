#!/bin/bash

set -e

gnugrep=/bin/grep
gnused=/bin/sed

case $OSTYPE in
        darwin*)
                #printf "running on macOS\n" >&2
                gnugrep=/usr/local/bin/ggrep
                gnused=/usr/local/bin/gsed
                ;;
esac



# adjust the timeout for n cores by increasing it by 20% for each core
# after the first one.  This compensates for the runtime lost through
# the shared memory bandwidth.
# $1: original timeout
# $2: number of processes
# prints new timeout
adjustTimeout()
{
	local increment=0.1
	#local timeout=`dc -e "20 k 1 $increment + $2 1 - ^ $1 * p"`
	local timeout=$1
	LC_NUMERIC=C printf %.0f $timeout
}

# $1: File to read through
# $2: Pattern to look for
countValid()
{
    $gnugrep "\\[$2\\].*Valid$" $1 | cut -d ' ' -f4 | sort -u | wc -l | tr -d ' \t'
}

# depending on whether TRUST_WP is defined, either collect counts
# from the individual "Goal ... Valid" messages or take them from the
# statistics WP returns. These are known to be invalid in certain
# versions of Frama-C, which is why both implementations exist.
#
# $1: name of the algorithm
# $2: tex command
# $3: tutorial section
extract_data_Wp()
{
    #printf "enter extract_data_Wp\n" >&2
    if [ $# -ne 3 ]
    then
        echo "please provide exactly three arguments" >&2
        exit 1
    fi

    example=$1
    cmd=$2
    sec=$3

    results=`mktemp ${TMPDIR-/tmp}/tempResults.XXXXXX`

    # if timeout is unset, assume no timeout (0)
    export WP_PROCESSES=${WP_PROCESSES:-1}
    export WP_TIMEOUT=`adjustTimeout ${WP_TIMEOUT:-0} $WP_PROCESSES`
    export WP_COQ_TIMEOUT=`adjustTimeout ${WP_COQ_TIMEOUT:-0} $WP_PROCESSES`
    export SCRIPT_DIR=${SCRIPT_DIR}

    REPORT_BACKEND=${REPORT_BACKEND:-default}

    case $REPORT_BACKEND in
    wp_runner) generate_wp_runner ;;
    vs-par) generate_vs_par ;;
    trust_wp|default) generate_wp ;;
    *) echo Unknown backend $REPORT_BACKEND ; exit 1 ;;
    esac

    case $REPORT_BACKEND in
    trust_wp|wp_runner|vs-par) extract_statistics ;;
    default) extract_raw_data_Wp $results ;;
    *) echo Unknown backend $REPORT_BACKEND ; exit 1 ;;
    esac

    rm -f $results
    #printf "exit extract_data_Wp\n" >&2
}

# $1: name of the algorithm
# $2: tex command
# $3: tutorial section
extract_data_Av()
{
    if [ $# -ne 3 ]
    then
        echo "please provide exactly three arguments" >&2
        exit 1
    fi

    example=$1
    cmd=$2
    sec=$3

    results=`mktemp ${TMPDIR-/tmp}/tempResults.XXXXXX`

    generate_av

    extract_statistics

    rm -f $results
}

# generate a verification report using WP directly
generate_wp()
{
    # generate directory for examples where everything is verified by Qed
    mkdir $example.wp

    # generate report
    local prog="$WP_C_REPORT \
        -wp-par $WP_PROCESSES \
        -wp-timeout $WP_TIMEOUT \
        -wp-coq-timeout $WP_COQ_TIMEOUT \
        -wp-out $example.wp $example.c"
    eval "$prog" >$results

    cp $results $example.wp/console.log
}

# generate a verification report using WP directly
generate_av()
{
    # generate report
    local prog="$AV_C_REPORT \
        -av-out $example.av $example.c"
    eval "$prog" >$results
}

# generate a verification report using the wp_runner script
generate_wp_runner()
{
	# assume we run from within an algorithm directory
	local prog="$SCRIPT_DIR/wp_runner.sh $example.c $WP_C_FLAGS $WP_PROVER_FLAGS -wp-par $WP_PROCESSES"
	eval "$prog" >$results
}

# generate a verification report using vs.sh
generate_vs_par()
{
	# assume we run from within an algorithm directory
	local prog="../../../Misc/VerificationService/vs.sh -p $example.c $WP_C_FLAGS $WP_PROVER_FLAGS -wp-par $WP_PROCESSES"
	eval "$prog" >$results 2>&1		# use stderr
}

# extract the number of fullfilled proof obligations by manually going
# through the output of WP and counting lines.
extract_raw_data_Wp()
{
    # pick up the number of generated goals
    local raw_output=$1
    goal_count=`$gnugrep "goals scheduled" $raw_output | cut -d ' ' -f2`
    valid_qed=`countValid $raw_output Qed`
    # use the following line for native alt_ergo
    #valid_alt_ergo=`countValid $raw_output Alt-Ergo`
    # use the following line for why3:alt_ergo
    valid_alt_ergo=`countValid $raw_output alt-ergo`
    valid_cvc4=`countValid $raw_output cvc4`
    valid_cvc3=`countValid $raw_output cvc3`
    valid_z3=`countValid $raw_output z3`
    valid_eprover=`countValid $raw_output eprover`
    valid_coq=`countValid $raw_output Coq`

    #calculate all valid goals
    valid=$(($valid_qed + $valid_alt_ergo + $valid_cvc4 + $valid_cvc3 + $valid_z3 + $valid_eprover + $valid_coq))

    print_statistics
}

# parse the report printed by WP (or WP runner) and generate figures from that
extract_statistics()
{
    # initialize validation variables with reasonable default values
    for i in qed alt_ergo cvc4 cvc3 z3 eprover coq
    do
        eval "valid_$i=0"
    done

    local statistics=`mktemp ${TMPDIR-/tmp}/tempStatistics.XXXXXX`

    # copy data for debugging
    #cp $results results.save

    # generate report
    $gnused -e 's,^.*Proved goals: *\([0-9]*\) / *\([0-9]*\),valid=\1;goal_count=\2,p' \
        -e '1,/^valid=/d' \
        -e 's/cvc4-[[:digit:]]*/cvc4/g' \
        -e 's/^ *\([^:() ]*\) *\(([^:()]*)\)\? *\(([^:()]*)\)\?:[[:space:]]*\([0-9]*\).*$/valid_\1=\4/' \
	-e '/+/d' \
	-e '/\<Done\>/d' $results |
    tr '[:upper:]-' '[:lower:]_' > $statistics

    # copy data for debugging
    #cp $statistics statistics.save
    . $statistics

    #printf "extract_statistics::valid_alt_ergo = $valid_alt_ergo\n" >&2

    print_statistics
    rm -f $statistics
}

# print the statistics extracted by extract_raw_data_Wp and
# extract_statistics
print_statistics()
{
    if [ ${goal_count:-0} -ne 0 ]
    then
        invalid=$(($goal_count - $valid))
        percent=$((100 * $valid / $goal_count))
    else
        invalid=0
        percent=100
    fi

    generate_report
}

# report fields
fields='example goal_count valid
    valid_qed valid_alt_ergo valid_cvc4 valid_cvc3 valid_z3 valid_eprover valid_coq
    invalid percent cmd sec'

# parse report fileand set variables accordingly
parse_report()
{
    # read report
    . $1

    # fill in missing fields
    for key in fields
    do eval : \${$key:=0}
    done
}

# generate a report file from the various variables and write it to stdout.
# the format of the report file is such that it can be parsed by parse_report.
generate_report()
{
    for key in $fields
    do
        eval value=\$$key
        echo $key=\'${value:-0}\'
    done
}

# read a report and pretty-print it to stdout
prettyPrintReport()
{
    parse_report $1
    printf  "   %-30s [%-4d %3d   (%3d %3d %3d %3d %3d %3d %3d)]     %3d%%\n" \
        $example $goal_count $valid \
        $valid_qed $valid_alt_ergo $valid_cvc4 $valid_cvc3 $valid_z3 $valid_eprover $valid_coq \
        $percent
}
