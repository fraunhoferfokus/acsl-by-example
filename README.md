

# ACSL by Example
[//]: # [![Replay Status](https://travis-ci.org/fraunhoferfokus/acsl-by-example.svg?branch=master)](https://travis-ci.org/fraunhoferfokus/acsl-by-example)

This repository contains version 22.0.0 of
[ACSL by Example](https://github.com/fraunhoferfokus/acsl-by-example/blob/master/ACSL-by-Example.pdf)
--- a collection of C functions and data types whose
behavior has been formally specified
with [ACSL](https://frama-c.com/acsl.html) and formally verified with [Frama-C/WP](https://frama-c.com/wp.html).

The directory
[StandardAlgorithms](https://github.com/fraunhoferfokus/acsl-by-example/tree/master/StandardAlgorithms)
contains the complete C source code including ACSL annotations of the examples.

This version of *ACSL by Example* is intended for
Frama-C 22.0 and relies among others on the following sofware packages.

*Package* | *Version*
--------- | ---------
 Why3     | 1.3.3
 Alt-Ergo | 2.3.3
 CVC4     | 1.7
 Z3       | 4.8.6
 Coq      | 8.12.1

For more details on verifying the examples see the file [README.txt](https://github.com/fraunhoferfokus/acsl-by-example/blob/master/StandardAlgorithms/README.txt).

## Accompanying LaTeX files

We also inlude for each example corresponding LaTeX file (see directory [Informal](https://github.com/fraunhoferfokus/acsl-by-example/tree/master/Informal)).
This might be interesting for someone who wants to apply machine learning algorithms
on this (small) collection of informal and formal specifications.
Note that these LaTeX files are not sufficient to generate
[ACSL by Example](https://github.com/fraunhoferfokus/acsl-by-example/blob/master/ACSL-by-Example.pdf).

## Travis CI

We have added Travis CI to demonstrate what steps are required to set up the toolchain, 
see the the 
file [.travis](https://github.com/fraunhoferfokus/acsl-by-example/blob/master/.travis.yml)
for details.
Travis performs the tests and replays the proofs with reduced timeouts.
This means the results in Travis are possibly downgraded compared to those
we report in the tutorial and the `Results` folder.

### Remark

In order to remain within the
[time limit](https://docs.travis-ci.com/user/customizing-the-build/#build-timeouts)
of Travis we omit the verification of
[sorting algorithms](https://github.com/fraunhoferfokus/acsl-by-example/tree/master/StandardAlgorithms/sorting).
In order to re-enable their verification, one has to add the line
`sorting` to [this file](https://github.com/fraunhoferfokus/acsl-by-example/blob/master/StandardAlgorithms/filelist.path).

