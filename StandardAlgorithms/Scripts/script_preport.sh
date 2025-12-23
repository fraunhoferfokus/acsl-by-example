#!/bin/bash

set -e

gnugrep=/bin/grep
gnused=/bin/sed
gnucat=/bin/cat

case $OSTYPE in
        darwin*)
                #printf "running on macOS\n" >&2
                gnugrep=/usr/local/bin/ggrep
                gnused=/usr/local/bin/gsed
                gnucat=/usr/local/bin/gcat
                ;;
esac

example=$1
cmd=$2
sec=$3
topdir=$4


result=$topdir/Results/$example.preport
wpdir=$example.wp

# Prover and report list need to have the same length

PROVERLIST=('Alt-Ergo' 'CVC4' 'CVC3' 'Z3' 'Coq')
REPORTLIST=('valid_alt_ergo' 'valid_cvc4' 'valid_cvc3' 'valid_z3' 'valid_coq')
echo "example='$example'" > $result
$gnucat $wpdir/console.log | sort -u > tmp.log #| $gnugrep "\[Qed\]" > tmp.log
#for i in $PROVERLIST
  #do
    #$gnucat console.log | $gnugrep -v '\[Qed\]' | $gnugrep $i >> tmp.log || true
  #done
# Cut the runtimes out of the log
$gnucat tmp.log | $gnused 's/(Qed:*.[0-9]ms)//g' | $gnused -E 's/Qed:[[:space:]]+[0-9]*//'| \
  $gnused 's/(*.[0-9]ms)//g' | $gnused 's/(*.[0-9]ms-//g' | \
  $gnused 's/ *.[0-9]ms-//g' | $gnused 's/Valid.*/Valid/' | $gnugrep "wp" | $gnugrep -v "Cache" |sort -u > $wpdir/$example.log

$gnucat $wpdir/$example.log | $gnused 's/\[wp\] //'| $gnused 's/Goal/:/' | $gnused 's/\[Qed\].*//' | $gnused 's/\[\(.*\) .*\]/\1/' | $gnused 's/Valid.*/Valid/p' | $gnused -n 's/ : Valid//p' | sort -u > $topdir/Results/$example.all

# Get the number of overall goals
printf "goal_count=" >> $result;
GOAL=`$gnused -n -e "s/^\[wp.*] Goal \([[:alnum:]_]*\) : .*/\1/p" $wpdir/$example.log | \
  sort -u | wc -l | $gnused 's/^[[:blank:]]*//'`;
printf "'$GOAL'\n" >> $result

# Get the number of valid goals
printf "valid=" >> $result;
VALID=`$gnused 's/Valid.*/Valid/' $wpdir/$example.log | \
    $gnused -n -e "s/^\[wp.*] Goal \([[:alnum:]_]*\) : Valid$/\1/p" | \
    sort -u | wc -l | $gnused 's/^[[:blank:]]*//'`;
printf "'$VALID'\n" >> $result 

# Remove the tmp file
rm -f tmp.log;

# get all goals that were verified by Qed
echo -n "valid_qed='" >> $result;
set +e; 
  $gnused 's/Valid.*/Valid/' $wpdir/$example.log | $gnugrep -c -E "^\[wp\] \[Qed] .* : Valid" | $gnused -e "s/$/'/" >> $result ; 
set -e; 

#get the goals that were proven by each prover in PROVERLIST
for i in ${!PROVERLIST[@]} 
do
  echo -n "${REPORTLIST[$i]}='" >> $result; \
		set +e; \
		proved_goal=`$gnugrep -c -E "^\[wp\] \[${PROVERLIST[$i]} .*] .* : Valid" $wpdir/$example.log | $gnused -e "s/$/'/"`; \
		set -e; \
                echo $proved_goal >> $result; \
done


# calculate number of goals that were not proven
printf "invalid=" >> $result;
printf "'$(($GOAL - $VALID))'\n" >> $result;

# calculate percentage of goals that were proven, 
# compared to the maximum goal count
printf "percent=" >> $result;
printf "'$((100 * VALID / GOAL))'\n" >> $result;

# include command and section
echo "cmd='"$cmd"'" >> $result;
echo "sec='"$sec"'" >> $result;
#rm -f format.log
#rm -f console.log
