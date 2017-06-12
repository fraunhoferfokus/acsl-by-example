#!/bin/sh

StandardAlgorithms=`dirname "$0"`/..
report=${1:-preport}
provers="alt_ergo cvc4 z3 cvc3 eprover coq"

. $StandardAlgorithms/Scripts/script_functions.sh

# print a newline separated list of all algorithm directories
all_algorithms() {
	for dir in `cat $StandardAlgorithms/filelist.path`
	do
		for alg in `cat $StandardAlgorithms/$dir/filelist.path`
		do
			echo $dir $alg
		done
	done
}

# check if prover $1 managed to prove all proof obligations.  If this is
# the case, print a space followed by the prover name.
proved_all() {
	eval valid_this=\${valid_$1}
	if [ $(($valid-$valid_qed)) -eq $valid_this ]
	then
		printf " %s" $1
	fi
}

# generate a report line indicating which provers for the report from
# stdin were able to prove all proof obligations.
prover_report_line() {
	parse_report $1
	printf "%s:" $alg

	for p in $provers
	do
		proved_all $p
	done

	echo
}

# generate the prover_report_line for all agorithms
prover_report() {
	all_algorithms | while read dir alg
	do
		prover_report_line $StandardAlgorithms/$dir/$alg/$alg.$report
	done
}

# for the prover report in $1 and the prover in $2, count how often
# the prover in $2 was best.
histogram() {
	printf "%-10s " $2:
	grep -c "\<$2\>" $1
}

tmpfile=`mktemp`
prover_report >$tmpfile
cat $tmpfile
echo

for p in $provers
do
	histogram $tmpfile $p
done | sort -n -r -k2

rm $tmpfile
