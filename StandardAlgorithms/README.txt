
A number of environment variables affect the generation of reports:
Please check Makefile.template for their precise definitions (including default values).

WP_TIMEOUT (1)
    The default timeout when running provers.  This value is multiplied
    by 1.1 for each additional process after the first in $WP_PROCESSES.

WP_COQ_TIMEOUT (5)
    The timeout for coq.  This timeout is scaled in the same way
    WP_TIMEOUT is.


WP_PROCESSES (1)
    The number of provers to run in parallel.

SCRIPT (wp0.script)
    The proof script used for discharging proof obligations with coq.
    You probably won't need to touch this variable.


Library of Standard Algorithms
================================

The directories 'mutating', 'nonmutating', 'binary_search', 'stack', 'maxmin' and so on
group algorithms together. Each contains subfolders for every specified algorithm.
In each folder <algorithm> you can find the following files:
<algorithm>.c		
<algorithm>.h		
<algorithm>_test.cpp	contains a C++ testfile where algorithm is compared to/with std::algorithm

If some obligations are proven with Coq, then there is a file 'wp0.script' which contains the proofs.
In addition each subfolder contains a makefile, see usage below.
Besides there is directory 'Scripts' to enable the makefile oppurtunities.

The directory 'Logic' is a collection of lemmas and logic functions used 
in the ACSL specifications. 

USAGE:
========

For individual examples, the most interesting targets are

make clean
- remove generate files in example directory

make wpgui
- runs Frama-C/WP on the example and shows the results in the Frama-C GUI

make wp
- runs Frama-C/WP on the example and shows the results on the command line


supported commands in directory StandardAlgorithms:
----------------------------------------------------

make clean	
- removes all generated files for each algorithm in the subfolders

make report-clean
- remove verification results for all examples

make preport-clean
- remove verification results for all examples and all provers

make test	
- compiles and runs the testfiles for each algorithm in the subfolders
- if successful it outputs: successful test of different <algorithm> implementations

make report
- generate verification results for all examples
- call 'make report-clean' before generating new reports

make preport
- generate verification results for all examples when running all provers on all 
  proof obligations
- call 'make preport-clean' before generating new reports

