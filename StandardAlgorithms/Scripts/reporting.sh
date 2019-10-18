
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

countValid()
{
    $gnugrep "\\[$2\\].*Valid$" $1 | cut -d ' ' -f4 | sort -u | wc -l | tr -d ' \t'
}

results=$1

goal_count=`$gnugrep "goals scheduled" $results | cut -d ' ' -f2`
valid_qed=`countValid $results Qed`
valid_alt_ergo=`countValid $results Alt-Ergo`
valid_cvc4=`countValid $results cvc4`
valid_cvc3=`countValid $results cvc3`
valid_z3=`countValid $results z3`
valid_eprover=`countValid $results eprover`
valid_coq=`countValid $results Coq`

printf "goal_count = $goal_count\n"
