

# ACSL by Example

This repository contains
[ACSL by Example](https://github.com/fraunhoferfokus/acsl-by-example/blob/master/ACSL-by-Example.pdf)
--- a collection of C functions and data types whose
behavior has been formally specified
with [ACSL](https://frama-c.com/acsl.html) and formally verified with [Frama-C/WP](https://frama-c.com/wp.html).

The directory
[StandardAlgorithms](https://github.com/fraunhoferfokus/acsl-by-example/tree/master/StandardAlgorithms)
contains the complete C source code including ACSL annotations of the examples.

This version of *ACSL by Example* is intended for
Frama-C 18.0 (_Argon_) and relies on the following other sofware packages.

*Package* | *Version*
--------- | ---------
 Why3     | 0.88.3
 Alt-Ergo | 2.2.0
 CVC4     | 1.6
 CVC3     | 2.4.1
 Z3       | 4.8.3
 E Prover | 2.2
 Coq      | 8.7.2

For more details on verifying the examples see the file [README.txt](https://github.com/fraunhoferfokus/acsl-by-example/blob/master/StandardAlgorithms/README.txt).
