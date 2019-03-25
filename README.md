

# ACSL by Example
[![Replay Status](https://travis-ci.org/fraunhoferfokus/acsl-by-example.svg?branch=ci)](https://travis-ci.org/fraunhoferfokus/acsl-by-example)

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

## Travis CI

We have added Travis CI to demonstrate what steps are required to set up the toolchain. Travis performs the tests and replays the proofs with reduced timeouts. That means the results in Travis are possibly downgraded comparing to that we state in the tutorial and the `Results` folder. Verification results are also could be different on your machine either because of the hardware. Please look at [StandardAlgorithms/README.txt](StandardAlgorithms/README.txt) for additional settings.
