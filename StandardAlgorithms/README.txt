Library of Standard Algorithms
================================

The directories 'mutating', 'nonmutating', 'binary_search', 'stack', 'maxmin' and 'set_algorithms'
group algorithms together. Each contains subfolders for every specified algorithm.
In each folder <algorithm> you can find the following files:
<algorithm>.c		
<algorithm>.h		
<algorithm>.impl	contains the implementation of the algorithm and possibly loop annotations
<algorithm>.spec	contains the specification of the function (function contract)
<algorithm>_test.cpp	contains a C++ testfile where algorithm is compared to/with std::algorithm

If some obligations are proven with Coq, then there is a file 'wp0.script' which contains the proofs.
In addition each subfolder contains a makefile, see usage below.
Besides there is directory 'Scripts' to enable the makefile oppurtunities.

The directory 'LogicSpecifications' is a collection of lemmas and logic functions used 
in the ACSL specifications. 
The directory 'tactics_lemmas_coq' contains tactics and lemmas to simplify proofs with Coq.

USAGE:
========

supported commands in directory StandardAlgorithms:
----------------------------------------------------
make
- see make report-wp (can be used alternatively)

make clean	
- removes all generated files for each algorithm in the subfolders

make test	
- compiles and runs the testfiles for each algorithm in the subfolders
- if successful it outputs: successful test of different <algorithm> implementations

make report-jessie
- starts deductive verification for each algorithm defined in the subfolders filelist.path 
  with Frama-C and Jessie using the batch-mode 
- uses the provers defined in variable PROVER_JESSIE in StandardAlgorithms/Makefile.template
- outputs shorter report of the results (number of VC's, valid VC's, percentage of valid VC's) 
  for each prover

make report-wp
- starts deductive verification for each algorithm defined in the subfolders filelist.path
  with Frama-C and WP using the batch-mode 
- uses the provers defined in variable PROVER_WP in StandardAlgorithms/Makefile.template
- uses time to prove for each VC defined in variable WP_TIMEOUT in StandardAlgorithms/Makefile.template
- outputs shorter report of the results (number of VC's, valid VC's, percentage of valid VC's) 
  for each prover

make report-coq
- starts deductive verification for each algorithm in filelist.path
  with Frama-C and WP using the batch-mode 
- in addition it looks for a proof script 'wp0.script' and applies the contained Coq proofs
- outputs a short report of the results (number of VC's, valid VC's, percentage of valid VC's) 
  and the number of goals proven with Coq
- attention: Coq proves should only carried out for not already proven 
             obligations. Otherwise it could yield a wrong percentage.
 

make format
- uses astyle to format the source code

supported commands in directory StandardAlgorithms/.../<algorithm>:
----------------------------------------------------------------
make clean	
- removes all automatically generated files from the current directory

make test	
- runs the C++ testfile
- if successful it outputs: successful test of different <algorithm> implementations
		
make report-jessie
- starts deductive verification of <algorithm> with Frama-C and Jessie using the batch-mode 
- outputs shorter report of the results (number of VC's, valid VC's, percentage of valid VC's) 
  for each prover

make report-wp
- starts deductive verification of <algorithm> with Frama-C and WP using the batch-mode 
- outputs shorter report of the results (number of VC's, valid VC's, percentage of valid VC's) 
  for each prover
  
make <algorithm>.jessie
- starts deductive verification of <algorithm> with Frama-C and Jessie using the GUI-mode 

make <algorithm>.wp
- starts deductive verification of <algorithm> with Frama-C and WP using the GUI-mode 

make <algorithm>.coq
- starts deductive verification of <algorithm> with Frama-C, WP and Coq using the GUI-mode 
- there are variables with defualt values defined in Makefile.template
- if needed, they can be set in the local Makefile or on the command line:
  - MEM_MODEL (specifies the memory model, default: store)
  - SCRIPT (specifies which script is used, default: wp0.script )
  - TACTICS (specifies the used tactics, default: store_tactics.v)
  - LEMMAS (specifies additional lemmas, default: lemmas.v)
 
make format
- uses astyle to format the source code

interesting environment variables
---------------------------------

A number of environment variables affect the generation of reports:

WP_TIMEOUT (20)
    The default timeout when running provers.  This value is multiplied
    by 1.1 for each additional process after the first in $WP_PROCESSES.

WP_COQ_TIMEOUT (20)
    The timeout for coq.  This timeout is scaled in the same way
    WP_TIMEOUT is.

WP_ALT_ERGO_STEPS (1000)
    The number of steps alt-ergo runs for before it is aborted.

WP_PROCESSES (1)
    The number of provers to run in parallel.

REPORT_BACKEND (default)
    One of trust_wp, wp_runner, and default.  Chooses how reports are
    generated: With default, the default backend is used.  trust_wp uses
    a different script to extract results from Frama C's output in a way
    that used to be broken.  wp_runner uses a custom script to run
    provers.  You probably won't need to touch this variable.

SCRIPT (wp0.script)
    The proof script used for discharging proof obligations with coq.
    You probably won't need to touch this variable.

FRAMAC_SHARE
    The path of a folder in the Frama C installation where Frama C
    stores a number importantant scripts and resources.  This variable
    is typically set in ~/.profile according to the location of your
    Frama C installation.
