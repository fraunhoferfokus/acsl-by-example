# Important Note: This software is not actively maintained anymore

As of 2021, *ACSL by Example* is **not maintained anymore**. 
The main reason is that my research centers now on quantum computing.
Although this field also demands for formal methods, I have not enough time to continue providing
high quality releases of *ACSL by Example*. 

It was a great pleasure for me to learn about the [Frama-C](https://frama-c.com) tool chain, in particular 
the [Frama-C/WP](https://frama-c.com/wp.html) plug-in.
We at Fraunhofer FOKUS could not have produced *ACSL by Example* without the great help we received
from the [team of Frama-C at CEA List](https://frama-c.com/html/contact.html)!

#### ACSL by Example

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

#### Accompanying LaTeX files

We also inlude for each example corresponding LaTeX file (see directory [Informal](https://github.com/fraunhoferfokus/acsl-by-example/tree/master/Informal)).
This might be interesting for someone who wants to apply machine learning algorithms
on this (small) collection of informal and formal specifications.
Note that these LaTeX files are not sufficient to generate
[ACSL by Example](https://github.com/fraunhoferfokus/acsl-by-example/blob/master/ACSL-by-Example.pdf).
