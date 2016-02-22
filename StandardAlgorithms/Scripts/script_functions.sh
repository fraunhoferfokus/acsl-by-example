#/bin/bash
 
#function equal: compares two stings and returns "0" if the strings are equal otherwise 0.

function equal () 
{
    case "$1" in "$2")
        return 0;;
    esac
    return 1
}

#function generateFile: creates an empty temporary file
function generateTempFile()
{
    #create an empty temporary file
    #deny access to temp file
    umask  007
    local temp=`mktemp ${TMPDIR-/tmp}/tempResults.XXXXXXXXXXXXXXXX` || exit 1
    eval $1=$temp;

}

# changes directory to the subdir specified in parameter #1 if the specified directory is not found the function will do nothing.
function changeToAlgDir()
{ 
    if  ! equal  $1 ${PWD##*/}
        then
        cd $1
fi
}


function checkAlg()
{  
    if [ -z "$1" ]
        then
            echo "missing argument 1: script expects an algorithm name; script will exit"
            exit 1
    fi
}




#needs a variable as argument
function changeEditor()
{
local temp= "error"
if [ "$(uname)" == Darwin ]
    then
    #  Mac OS X platform
     temp="gsed"
elif [ "$(uname)" == Linux ]
then
     temp="sed"
else 
    echo"an error has been detected"
fi

#echo " prgEE: ${temp}"
eval $1=$temp;
}



function countData()
{
    local  search_pattern='[\t | ][\t | ]*'
    local replace_pattern='\t'
     $prg_sed -e 's/${search_pattern}/${replace_pattern}/g' |cut -f4 |sort -u| wc -l

    unset search_pattern 
    unset replace_pattern 
}


# arg1: name of the algorithm
function extract_raw_data_Wp()
{
    local alg=${1##*/}
   # local prover=${2##*/}
    checkAlg $alg
    #changeToAlgDir $alg
    local tempFile
    local tempFile2
    local goalCount=0
    local prg_sed
    changeEditor prg_sed
    local valid_qed=0
    local valid_alt_ergo=0
    local valid_cvc4=0
    local valid_z3=0
    local valid_coq=0
    local invalid=0
    local valid=0

    #generate temporary files
    generateTempFile tempFile
    generateTempFile tempFile2

    wp_pattern='^\[wp\]+[[:blank:]]+'
    valid_pattern='[[:print:]]*[[:blank:]]+Valid'
    coq_pattern=${wp_pattern}'\[Coq\]'${valid_pattern}
    cvc4_pattern=${wp_pattern}'\[cvc4\]'${valid_pattern}
    z3_pattern=${wp_pattern}'\[z3\]'${valid_pattern}
    qed_pattern=${wp_pattern}'\[Qed\]'${valid_pattern}
    alt_ergo_pattern=${wp_pattern}'\[Alt-Ergo\]'${valid_pattern}
    goalPattern=${wp_pattern}'[[:digit:]]+[[:blank:]]+goals[[:blank:]]+scheduled'

    #set -vx
    prog="${WP_C_REPORT} -wp-par 1 -wp-out ${alg}.wp ${alg}.c"

    eval "$prog"> $tempFile
    #debug
    #cat $tempFile >fillFull.debug
    # pick up the number of generated goals
    let "goalCount= $goalCount + `grep -E $goalPattern $tempFile | $prg_sed -e 's/[\t | ][\t | ]*/\t/g' | cut -f2`"
    #debug
    #cat $tempFile > fill.debug

    let "valid_qed=$valid_qed + `grep -E $qed_pattern $tempFile |countData`"
    let "valid_alt_ergo=$valid_alt_ergo + `grep -E $alt_ergo_pattern $tempFile |countData`"
    let "valid_coq=$valid_coq + `grep -E $coq_pattern $tempFile |countData`"
    let "valid_cvc4=$valid_cvc4 + `grep -E $cvc4_pattern $tempFile |countData`"
    let "valid_z3=$valid_z3 + `grep -E $z3_pattern $tempFile |countData`"

    #cat $tempFile > fillFull.debug
    #calculate all valid goals
    let "valid=$valid_qed + $valid_alt_ergo + $valid_cvc4 + $valid_z3 + $valid_coq"
    printf "%s;%d;%d;%d;%d;%d;%d;%d;\n" $alg $goalCount $valid $valid_qed $valid_alt_ergo $valid_cvc4 $valid_z3 $valid_coq

    #debug
    #cat $tempFile2 > fill1.debug

    #cleanup variables
    unset prog
    unset pattern
    unset goalPattern
    unset goalCount
    unset alg
    unset prg_sed
    unset valid
  #  #delete temporary file on exit
    trap 'rm -f $tempfile' EXIT
    trap 'rm -f $tempFile2' EXIT
}


#reads raw date from stdout and generates a report

#first arg: algorithm name
#second arg: tex-command
function genTableEntry()
{
   # echo "dldkfdlk"
    local cmd=${2##*/}
    local sec=${3##*/}
    local goalCount=0
    local valid=0
    local valid_qed=0
    local valid_alt_ergo=0
    local valid_cvc4=0
    local valid_z3=0
    local valid_coq=0
    local percent=0
    local invalid=0
    local tempFile
    generateTempFile tempFile


    local prg_sed
    changeEditor prg_sed

    #algorithm name;
    #number of generated goals
    #valid goals;
    #valid goals proved by qed;
    #valid goals proved by alt-ergo;
    #valid goals proved by coq;


    #call function extract_raw_data_wp and formating the output
    extract_raw_data_Wp $1 |$prg_sed -e 's/;/\t/g' > $tempFile
    #cat $tempFile
    let "goalCount= $goalCount + `cat $tempFile |  cut -f2`"
    let "valid= $valid + `cat $tempFile |  cut -f3`"
    let "valid_qed= $valid_qed + `cat $tempFile |  cut -f4`"
    let "valid_alt_ergo= $valid_alt_ergo + `cat $tempFile |  cut -f5`"
    let "valid_cvc4= $valid_cvc4 + `cat $tempFile |  cut -f6`"
    let "valid_z3= $valid_z3 + `cat $tempFile |  cut -f7`"
    let "valid_coq= $valid_coq + `cat $tempFile |  cut -f8`"
    if [ $goalCount -ne 0 ]
        then
             let "invalid=$goalCount -$valid"
             let "percent=(100*$valid)/$goalCount"
        else    percent=0
        fi
    printf "%-5s & \\\\ref{%-5s} & %-3d  & %3d   & %-3d  & %3d  & %3d  & %3d  & %3d  & %3d \\\\\\\\\hline\n" $cmd $sec $valid $goalCount $percent $valid_qed $valid_alt_ergo $valid_cvc4 $valid_z3 $valid_coq  > ${1}.tex

    unset cmd
    unset sec
    unset goalCount
    unset invalid
    unset percent
    unset valid
    unset prg_sed
  #  #delete temporary file on exit
    trap 'rm -f $tempfile' EXIT

}

#reads raw date from stdout and generates a report
function reportWp()
{
   # echo "dldkfdlk"
    local goalCount=0
    local valid=0
    local valid_qed=0
    local valid_alt_ergo=0
    local valid_cvc4=0
    local valid_z3=0
    local valid_coq=0
    local percent=0
    local invalid=0
    local tempFile
    generateTempFile tempFile


    local prg_sed
    changeEditor prg_sed

    #algorithm name;
    #number of generated goals
    #valid goals;
    #valid goals proved by qed;
    #valid goals proved by alt-ergo;
    #valid goals proved by coq;


    #call function extract_raw_data_wp and formating the output
    extract_raw_data_Wp $1 |$prg_sed -e 's/;/\t/g' > $tempFile
    #cat $tempFile
    let "goalCount= $goalCount + `cat $tempFile |  cut -f2`"
    let "valid= $valid + `cat $tempFile |  cut -f3`"
    let "valid_qed= $valid_qed + `cat $tempFile |  cut -f4`"
    let "valid_alt_ergo= $valid_alt_ergo + `cat $tempFile |  cut -f5`"
    let "valid_cvc4= $valid_cvc4 + `cat $tempFile |  cut -f6`"
    let "valid_z3= $valid_z3 + `cat $tempFile |  cut -f7`"
    let "valid_coq= $valid_coq + `cat $tempFile |  cut -f8`"
    if [ $goalCount -ne 0 ]
        then
             let "invalid=$goalCount -$valid"
             let "percent=(100*$valid)/$goalCount"
        else    percent=0
        fi
    printf  "   verify  %-35s [%-4d %3d   (%-3d %3d %3d %3d %3d)]     %3d%%\n" $1 $goalCount $valid $valid_qed $valid_alt_ergo $valid_cvc4 $valid_z3 $valid_coq $percent


    unset goalCount
    unset invalid
    unset percent
    unset valid
    unset prg_sed
  #  #delete temporary file on exit
    trap 'rm -f $tempfile' EXIT

}

# input wp-report dateien 1-n : n<=9
# the last argument is the reference where the function saves the path to outputfile.
#function creates an inputfile for gnuplot

function statisticsWp()
{
    #generate a temporary file
    generateTempFile tempFile
    #debug
    echo "number of arguments $#"
    #generate file head

}

