
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

make report
- runs Frama-C/WP on the example and shows the results on the command line


supported commands in directory StandardAlgorithms:
----------------------------------------------------

make clean	
- removes all generated files for each algorithm in the subfolders

make report-clean
- remove verification results for all examples

make test	
- compiles and runs the testfiles for each algorithm in the subfolders
- if successful it outputs: successful test of different <algorithm> implementations

make report
- generate verification results for all examples
- call 'make report-clean' before generating new reports

