#!/bin/bash

set -e

gnutime=/usr/bin/time
gnuxargs=/usr/bin/xargs
gnugrep=/bin/grep
gnused=/bin/sed

case $OSTYPE in
	linux*)
		#printf "running on Linux\n" >&2
		;;
	darwin*)
		#printf "running on macOS\n" >&2
		gnutime=/usr/local/bin/gtime
		gnuxargs=/usr/local/bin/gxargs
                gnugrep=/usr/local/bin/ggrep
                gnused=/usr/local/bin/gsed
		;;
	*)
		#printf "running on untested $OSTYPE\n" >&2
esac


FRAMAC_SHARE=${FRAMAC_SHARE:-$(frama-c -print-share-path)}
WP_TIMEOUT=${WP_TIMEOUT:-20}

# this exit status is used when wp_runner terminates a process due to
# it reaching its timeout.
timeout_status=42

# parse the options to Frama C to get the list of provers
# the argument list to this shoul be the argument list to the script.
# This needs to be a function so we can walk the argument list without
# destroying it
get_provers() {
	echo Qed
	while [ $# -gt 1 ]
	do
		if [ "$1" = -wp-prover ]
		then
			echo $2
			shift
		fi
		shift
	done
}



# For each verification condition, generate task strings that can be
# passed to xargs for parallel execution.
generate_tasks() {
	# there may not be any why file in $wpdir/typed_external, so enable
	# nullglob and pass /dev/null so grep doesn't consider stdin if
	# no file matches.
	shopt -s nullglob
	# FIXME "typed_external" depends on memory model and driver
	for whyfile in $wpdir/typed_external/*.why
	do
		$gnused -n \
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
		theoryname=typed_external_${theory#VC}
		;;
	Q_*)
		theory=${whyfile##*/}
		theory=${theory%.why}
		theoryname=typed_external_lemma_${vc#Q_}
		goalopt="-G $vc"
		;;
	*)
		echo Unrecognized verification condition $vc >&2
		exit 1
	esac

	outname=$wpdir/typed_external/${theoryname}_Why3_$prover
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
		result="$($gnused -n -e "s/ WP \?/ /" \
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

	why3 prove "$@" \
		-t $WP_TIMEOUT \
		--extra-config $FRAMAC_SHARE/wp/why3/why3.conf \
		-L $wpdir/typed_external \
		-L $FRAMAC_SHARE/wp/why3/ \
		-T $theory \
		-P $prover \
		$goalopt
}

# invoke coqc with the Coq-script derived from $1. TODO: Find out how to
# cause frama-c to generate that script.
call_coqc() {
	if [ ${WP_TIMEOUT:-0} -gt 0 ]
	then
		ulimit -S -t $WP_TIMEOUT
	fi

	# TODO
	exit 4
	coqscript=...

	coqc -R $FRAMAC_SHARE/wp/coqwp '' \
		-R $FRAMAC_SHARE/wp/coqwp/int int \
		-R $FRAMAC_SHARE/wp/coqwp/real real \
		-R $FRAMAC_SHARE/wp/coqwp/map map \
		-R $DRIVER_DIR '' \
		-noglob $wpdir/typed_external/$coqscript
}

# read the logfile $log, compute the number of proved goals and generate
# a report line showing how many goals have been proven.
proved_goals() {
	# first count how many goals we found
	goals=`$gnused -n -e 's/^\[wp.*] Goal \([[:alnum:]_]*\) : .*$/\1/p' $log | sort -u | wc -l`

	# next, extract goal names and count how many were found to be valid
	valid=`$gnused -n -e 's/^\[wp.*] Goal \([[:alnum:]_]*\) : Valid$/\1/p' $log | sort -u | wc -l`

	printf '[wprunner] Proved goals:  %3d /%3d\n' $valid $goals
}

# compute how many proof obligations prover $1 managed to verify and
# print a line for the statistics
goals_by_prover() {
	prover=$1
	#printf "$prover\n" >&2 

	set +e
	count=`$gnugrep -c -E '^\[wp(runner)?] \['$prover'] .* : Valid$' $log`
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
if [ "$1" = '-r' ]
then
	# if there are no proof obligations, do_proof will be called
	# once without a proof obligation.  Catch that case.
	[ $# -lt 3 ] && exit

	echo "$3" | do_proof $2
	exit
fi


# make sure we don't get any surprises later
if [ -z "$FRAMAC_SHARE" ]
then
	echo "[wprunner] Don't know where my \$FRAMAC_SHARE is. Please tell me!"
	exit 1
fi

# NPROC should contain the number of CPUs to use.
# by defaut, we use WP_PROCESSES but if that isn't set we try to set
# NPROC by guessing the number of processors.
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

provers=`get_provers "$@" | $gnused s/why3:// | sort -f`
echo [wprunner] Provers: $provers
source=$1
wpdir=${source%.c}.wp
log=$wpdir/wp_runner.log
shift

rm -rf $wpdir
mkdir $wpdir
: > $log

echo [wprunner] Generating WP files | tee -a $log
echo "WP = $FR" | tee -a $log
echo "$@" | tee -a $log
($gnutime -a -o $log -f "\t%e seconds to generate VC" $FR "$@" -wp-out $wpdir -wp-gen $source) | tee -a $log
echo | tee -a $log

echo [wprunner] Running provers on $NPROC CPUs | tee -a $log

tasks=$(mktemp)
trap "rm -f $tasks" EXIT
eval generate_tasks > $tasks
$gnutime -a -o $log -f "\t%e seconds to discharge VC" $gnuxargs -P $NPROC -n 1 -a $tasks -- $0 -r $wpdir | tee -a $log

# print statistics
proved_goals
for prover in $provers
do
	goals_by_prover $prover
done
#printf "printing proved goals done\n" >&2
