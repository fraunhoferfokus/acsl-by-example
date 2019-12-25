
A number of environment variables affect the generation of reports:
Please check Makefile.template for their precise definitions (including default values).

WP_TIMEOUT (10)
    The default timeout when running provers.  This value is multiplied
    by 1.1 for each additional process after the first in $WP_PROCESSES.

WP_COQ_TIMEOUT (10)
    The timeout for coq.  This timeout is scaled in the same way
    WP_TIMEOUT is.


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


Library of Standard Algorithms
================================

The directories 'mutating', 'nonmutating', 'binary_search', 'stack', 'maxmin' and 'set_algorithms'
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

supported commands in directory StandardAlgorithms:
----------------------------------------------------
make
- see make report-wp (can be used alternatively)

make clean	
- removes all generated files for each algorithm in the subfolders

make test	
- compiles and runs the testfiles for each algorithm in the subfolders
- if successful it outputs: successful test of different <algorithm> implementations

make format
- uses astyle to format the source code

supported commands in directory StandardAlgorithms/.../<algorithm>:
----------------------------------------------------------------
make clean	
- removes all automatically generated files from the current directory

make test	
- runs the C++ testfile
- if successful it outputs: successful test of different <algorithm> implementations

make <algorithm>.wp
- starts deductive verification of <algorithm> with Frama-C and WP using the GUI-mode 

make format
- uses astyle to format the source code

---------------------------------
