#!/bin/bash

set -e

# adjust the timeout for n cores by increasing it by 20% for each core
# after the first one.  This compensates for the runtime lost through
# the shared memory bandwidth.
# $1: original timeout
# $2: number of processes
# prints new timeout
adjustTimeout()
{
	local increment=0.1
	local timeout=`dc -e "20 k 1 $increment + $2 1 - ^ $1 * p"`
	LC_NUMERIC=C printf %.0f $timeout
}

# $1: File to read through
# $2: Pattern to look for
countValid()
{
    grep "\\[$2\\].*Valid$" $1 | cut -d ' ' -f4 | sort -u | wc -l | tr -d ' \t'
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
    if [ $# -ne 3 ]
    then
        echo "please provide exactly three arguments"
        exit 1
    fi

    alg=$1
    cmd=$2
    sec=$3

    results=`mktemp ${TMPDIR-/tmp}/tempResults.XXXXXX`

    # if timeout is unset, assume no timeout (0)
    export WP_PROCESSES=${WP_PROCESSES:-1}
    export WP_TIMEOUT=`adjustTimeout ${WP_TIMEOUT:-0} $WP_PROCESSES`
    export WP_COQ_TIMEOUT=`adjustTimeout ${WP_COQ_TIMEOUT:-0} $WP_PROCESSES`

    REPORT_BACKEND=${REPORT_BACKEND:-default}

    case $REPORT_BACKEND in
    wp_runner) generate_wp_runner ;;
    trust_wp|default) generate_wp ;;
    *) echo Unknown backend $REPORT_BACKEND ; exit 1 ;;
    esac

    case $REPORT_BACKEND in
    trust_wp|wp_runner) extract_statistics_Wp ;;
    default) extract_raw_data_Wp ;;
    *) echo Unknown backend $REPORT_BACKEND ; exit 1 ;;
    esac

    rm -f $results
}

# generate a verification report using WP directly
generate_wp()
{
    # generate report
    local prog="$WP_C_REPORT \
        -wp-par $WP_PROCESSES \
        -wp-timeout $WP_TIMEOUT \
        -wp-coq-timeout $WP_COQ_TIMEOUT \
        -wp-out $alg.wp $alg.c"
    eval "$prog" >$results
}

# generate a verification report using the wp_runner script
generate_wp_runner()
{
	# assume we run from within an algorithm directory
	local prog="../../Scripts/wp_runner.sh $alg.c $WP_C_FLAGS $WP_PROVER_FLAGS -wp-par $WP_PROCESSES"
	eval "$prog" >$results
}

# extract the number of fullfilled proof obligations by manually going
# through the output of WP and counting lines.
extract_raw_data_Wp()
{

    # pick up the number of generated goals
    goal_count=`grep "goals scheduled" $results | cut -d ' ' -f2`
    valid_qed=`countValid $results Qed`
    valid_alt_ergo=`countValid $results Alt-Ergo`
    valid_coq=`countValid $results Coq`
    valid_cvc4=`countValid $results cvc4`
    valid_cvc3=`countValid $results cvc3`
    valid_z3=`countValid $results z3`
    valid_eprover=`countValid $results eprover`

    #calculate all valid goals
    valid=$(($valid_qed + $valid_alt_ergo + $valid_cvc4 + $valid_z3 + $valid_cvc3 + $valid_coq + $valid_eprover))

    print_statistics
}

# parse the report printed by WP (or WP runner) and generate figures from that
extract_statistics_Wp()
{
    # initialize validation variables with reasonable default values
    for i in qed alt_ergo coq cvc4 cvc3 z3 eprover
    do
        eval "valid_$i=0"
    done

    local statistics=`mktemp ${TMPDIR-/tmp}/tempStatistics.XXXXXX`

    # generate report
    sed -e 's,^.*Proved goals: *\([0-9]*\) / *\([0-9]*\),valid=\1;goal_count=\2,p' \
        -e '1,/^valid=/d' \
        -e 's/^ *\([^:]*\): *\([0-9]*\).*$/valid_\1=\2/' $results |
    tr '[:upper:]-' '[:lower:]_' >$statistics

    source $statistics
    rm -f $statistics

    print_statistics
}

# print the statistics extracted by extract_raw_data_Wp and
# extract_statistics_Wp
print_statistics()
{
    if [ $goal_count -ne 0 ]
    then
        invalid=$(($goal_count - $valid))
        percent=$((100 * $valid / $goal_count))
    else
        invalid=0
        percent=0
    fi

    echo $alg $goal_count $valid $valid_qed $valid_alt_ergo $valid_cvc4 $valid_z3 $valid_cvc3 $valid_eprover $valid_coq $invalid $percent $cmd $sec
}

# read a report from stdin and pretty-print it to stdout
prettyPrintReport()
{
    local alg
    local cmd
    local sec
    local goal_count
    local valid
    local valid_qed
    local valid_alt_ergo
    local valid_cvc4
    local valid_z3
    local valid_cvc3
    local valid_coq
    local percent
    local invalid

    read -r alg goal_count valid valid_qed valid_alt_ergo valid_cvc4 valid_z3 valid_cvc3 valid_eprover valid_coq invalid percent cmd sec
    printf  "   %-30s [%-4d %3d   (%3d %3d %3d %3d %3d %3d %3d)]     %3d%%\n" \
        $alg $goal_count $valid $valid_qed $valid_cvc4 $valid_z3 $valid_alt_ergo $valid_cvc3 $valid_eprover $valid_coq $percent
}
