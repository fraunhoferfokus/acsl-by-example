

# ACSL by Example
[![Replay Status](https://travis-ci.org/fraunhoferfokus/acsl-by-example.svg?branch=master)](https://travis-ci.org/fraunhoferfokus/acsl-by-example)

This repository contains
[ACSL by Example](https://github.com/fraunhoferfokus/acsl-by-example/blob/master/ACSL-by-Example.pdf)
--- a collection of C functions and data types whose
behavior has been formally specified
with [ACSL](https://frama-c.com/acsl.html) and formally verified with [Frama-C/WP](https://frama-c.com/wp.html).

The directory
[StandardAlgorithms](https://github.com/fraunhoferfokus/acsl-by-example/tree/master/StandardAlgorithms)
contains the complete C source code including ACSL annotations of the examples.

This version of *ACSL by Example* is intended for
Frama-C 20.0 and relies among others on the following sofware packages.

*Package* | *Version*
--------- | ---------
 Why3     | 1.2.1
 Alt-Ergo | 2.3.1
 CVC4     | 1.6
 CVC3     | 2.4.1
 Z3       | 4.8.6
 Coq      | 8.9.1

For more details on verifying the examples see the file [README.txt](https://github.com/fraunhoferfokus/acsl-by-example/blob/master/StandardAlgorithms/README.txt).

## Travis CI

We have added Travis CI to demonstrate what steps are required to set up the toolchain, 
see the the 
file [.travis](https://github.com/fraunhoferfokus/acsl-by-example/blob/master/.travis.yml)
for details.
Travis performs the tests and replays the proofs with reduced timeouts.
That means the results in Travis are possibly downgraded comparing to that we state in the tutorial and the `Results` folder.
Verification results are also could be different on your machine either because of the hardware.
Please look at [StandardAlgorithms/README.txt](StandardAlgorithms/README.txt) for additional settings.
