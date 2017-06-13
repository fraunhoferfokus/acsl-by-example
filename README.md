

**ACSL by Example**

This repository contains
[*ACSL by Example*](https://github.com/fraunhoferfokus/acsl-by-example/blob/master/ACSL-by-Example.pdf)
--- a collection of C functions and data types whose
behavior has been formally specified
with [ACSL](https://www.frama-c.com/acsl.html) and formally verified with [Frama-C/WP](https://www.frama-c.com/wp.html).

 *ACSL by Example* is developed and maintained by the
 [*Verification Group*](https://www.fokus.fraunhofer.de/en/sqc/verification)
 at [Fraunhofer FOKUS](https://www.fokus.fraunhofer.de/en) .

The directory
[StandardAlgorithms](https://github.com/fraunhoferfokus/acsl-by-example/tree/master/StandardAlgorithms)
contains the complete C source code (including the ACSL annotations) of the examples.

This version of *ACSL by Example* is intended for
[Frama-C 15 Phosphorus](https://www.frama-c.com/download.html)
and relies on the following other software packages.

* Why3      0.87.3
* Alt-Ergo	1.30
* Z3        4.5.1
* CVC4      1.4
* CVC3      2.4.1
* E Prover	1.9
* Coq       8.5.3

For more details on verifying the examples see the file [README.txt](https://github.com/fraunhoferfokus/acsl-by-example/blob/master/StandardAlgorithms/README.txt).
