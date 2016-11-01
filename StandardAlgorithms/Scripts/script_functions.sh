#!/bin/bash

set -e

# $1: File to read through
# $2: Pattern to look for
countValid()
{
    grep "\\[$2\\].*Valid$" $1 | cut -d ' ' -f4 | sort -u | wc -l | tr -d ' \t'
}

# $1: name of the algorithm
# $2: tex command
# $3: tutorial section
extract_raw_data_Wp()
{
    if [ $# -ne 3 ]
    then
        echo "please provide exactly three arguments"
        exit 1
    fi

    local alg=$1
    local cmd=$2
    local sec=$3

    # generate report
    local tempFile=`mktemp ${TMPDIR-/tmp}/tempResults.XXXXXX`
    local prog="$WP_C_REPORT -wp-par 1 -wp-out $alg.wp $alg.c"
    eval "$prog" >$tempFile

    # pick up the number of generated goals
    local goalCount=`grep "goals scheduled" $tempFile | cut -d ' ' -f2`
    local valid_qed=`countValid $tempFile Qed`
    local valid_alt_ergo=`countValid $tempFile Alt-Ergo`
    local valid_coq=`countValid $tempFile Coq`
    local valid_cvc4=`countValid $tempFile cvc4`
    local valid_cvc3=`countValid $tempFile cvc3`
    local valid_z3=`countValid $tempFile z3`
    local valid_eprover=`countValid $tempFile eprover`

    rm -f $tempFile

    #calculate all valid goals
    local valid=$(($valid_qed + $valid_alt_ergo + $valid_cvc4 + $valid_z3 + $valid_cvc3 + $valid_coq + $valid_eprover))

    local invalid
    local percent

    if [ $goalCount -ne 0 ]
    then
        invalid=$(($goalCount - $valid))
        percent=$((100 * $valid / $goalCount))
    else
        invalid=0
        percent=0
    fi

    echo $alg $goalCount $valid $valid_qed $valid_alt_ergo $valid_cvc4 $valid_z3 $valid_cvc3 $valid_eprover $valid_coq $invalid $percent $cmd $sec
}

# read a report from stdin and pretty-print it to stdout
prettyPrintReport()
{
    local alg
    local cmd
    local sec
    local goalCount
    local valid
    local valid_qed
    local valid_alt_ergo
    local valid_cvc4
    local valid_z3
    local valid_cvc3
    local valid_coq
    local percent
    local invalid

    read -r alg goalCount valid valid_qed valid_alt_ergo valid_cvc4 valid_z3 valid_cvc3 valid_eprover valid_coq invalid percent cmd sec
    printf  "   %-30s [%-4d %3d   (%3d %3d %3d %3d %3d %3d %3d)]     %3d%%\n" \
        $alg $goalCount $valid $valid_qed $valid_cvc4 $valid_z3 $valid_alt_ergo $valid_cvc3 $valid_eprover $valid_coq $percent
}
