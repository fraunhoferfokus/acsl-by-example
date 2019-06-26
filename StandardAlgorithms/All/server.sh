#!/bin/bash

set -e

# For each verification condition, generate task strings that can be
# passed to xargs for parallel execution.
generate_tasks() {
	#echo $wpdir
	# there may not be any why file in $wpdir/typed_ref_external, so enable
	# nullglob and pass /dev/null so grep doesn't consider stdin if
	# no file matches.
	shopt -s nullglob
	for whyfile in $wpdir/typed_ref_external/*.why
	do
		sed -n \
		    -e 's/^theory \(VC.*\)$/\1/p' \
		    -e 's/^lemma \(Q_.*\):$/\1/p' \
		    $whyfile | while read -r theory
		do
                        for prover in $provers
                        do
                                # Qed is invoked directly by WP, not by us
				[ $prover = Qed ] && continue
				echo $whyfile:$theory:$prover
			done
		done
	done
}


# This function takes a why file, and a verification conditon in this
# why file and validates it.
do_proof() {
	wpdir=$1
	IFS=: read -r whyfile vc prover
	goalopt=

	case $vc in
	VC*)
		theory=$vc
		theoryname=typed_ref_external_${theory#VC}
		;;
	Q_*)
		theory=${whyfile##*/}
		theory=${theory%.why}
		theoryname=typed_ref_external_lemma_${vc#Q_}
		goalopt="-G $vc"
		;;
	*)
		echo Unrecognized verification condition $vc >&2
		exit 1
	esac

	outname=$wpdir/typed_ref_external/${theoryname}_Why3_$prover
	set +e
	(
		case $prover in
		coq) call_coqc $why ;;
		*) call_why3 $whyfile ;;
		esac
	) 3>&1 >$outname.out 2>$outname.err
	status=$?
	set -e

	if [ $status -ne 0 ]
	then
		result="Error $status"
	elif [ -s $outname.out ]
	then
		result="$(sed -n -e "s/ WP / /" \
		    -e "s/^.* [[:alnum:]_]* : \\([[:alnum:]]*\\) .*$/\\1/p" $outname.out)"
	else
		result=Unknown
	fi

	# TODO: Extract success/failure information
	printf "[wprunner] [%s] Goal %s : %s\n" "$prover" "$theoryname" "$result"
}


# invoke why3 with $* as its arguments.  If ULIMIT_TIMEOUT is set,
# the prover's timeout will be set by configuring an appropriate ulimit
# otherwise by passing an appropriate -t option.

call_why3() {
        trap "exit $timeout_status" XCPU


        if [ ${ULIMIT_TIMEOUT:-0} != 0 ] && [ ${WP_TIMEOUT:-0} -gt 0 ]
        then
                ulimit -S -t $WP_TIMEOUT
                WP_TIMEOUT=0
        fi

        # fix later
	WP_TIMEOUT=10

        why3 prove "$@" \
                -t $WP_TIMEOUT \
                --extra-config $FRAMAC_SHARE/wp/why3/why3.conf \
                -L $wpdir/typed_ref_external \
                -L $FRAMAC_SHARE/wp/why3/ \
                -T $theory \
                -P $prover \
                $goalopt
}


# read the logfile $log, compute the number of proved goals and generate
# a report line showing how many goals have been proven.
proved_goals() {
        # first count how many goals we found
        goals=`sed -n -e 's/^\[wp.*] Goal \([[:alnum:]_]*\) : .*$/\1/p' $log | sort -u | wc -l`

        # next, extract goal names and count how many were found to be valid
        valid=`sed -n -e 's/^\[wp.*] Goal \([[:alnum:]_]*\) : Valid$/\1/p' $log | sort -u | wc -l`

        printf '[wprunner] Proved goals:  %3d /%3d\n' $valid $goals
}

# compute how many proof obligations prover $1 managed to verify and
# print a line for the statistics
goals_by_prover() {
        prover=$1

        set +e
        count=`grep -c -E '^\[wp(runner)?] \['$prover'] .* : Valid$' $log`
        set -e

        printf "           %-15s%3d\n" $prover: $count
}


# this script generates the same .wp directory frama-c -wp-proof-trace
# would generate.  The first argument to this script is the source file
# to verify, the remaining arguments are passed to frama-c.
#
# a first argument of -r (for recursive) indicates that we are being
# called recursively to prove a single task. See do_proof for details.
#
# If the script runs with -r, the arguments have the following meaning:
# $1: -r
# $2: wpdir
# $3: $whyfile:$theory:$prover

if [ $1 = '-r' ]
then
        # if there are no proof obligations, do_proof will be called
        # once without a proof obligation.  Catch that case.
        [ $# -lt 3 ] && exit

        echo "$3" | do_proof $2
        exit
fi


wpdir=all.wp
provers="Qed alt-ergo cvc4 cvc3 z3 eprover"
log=$wpdir/wp_runner.log

WP_TIMEOUT=10

if [ -z "$NPROC" ]
then
        if [ -z "$WP_PROCESSES" ]
        then
                case `uname -s` in
                Linux) NPROC=`nproc`;;
                Darwin|FreeBSD) NPROC=`sysctl -n hw.ncpu`;;
                *) NPROC=1;;
                esac
        else
                NPROC=$WP_PROCESSES
        fi
fi

#echo $NPROC >&2

#???
generate_tasks | xargs -P $NPROC -n 1 -- $0 -r $wpdir | tee -a $log


# print statistics
proved_goals
for prover in $provers
do
        goals_by_prover $prover
done

