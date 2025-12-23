
# ACSL by Example

This repository contains version 32.0.0 of
[ACSL by Example](https://github.com/fraunhoferfokus/acsl-by-example/blob/master/ACSL-by-Example.pdf)
--- a collection of C functions and data types whose
behavior has been formally specified
with [ACSL](https://frama-c.com/acsl.html) and formally verified with [Frama-C/WP](https://frama-c.com/wp.html).

The directory
[StandardAlgorithms](https://github.com/fraunhoferfokus/acsl-by-example/tree/master/StandardAlgorithms)
contains the complete C source code including ACSL annotations of the examples.

This version of *ACSL by Example* is intended for
[Frama-C 32.0 (Germanium)](https://www.frama-c.com/fc-versions/germanium.html)
 and relies among others on the following sofware packages.

*Package* | *Version*
--------- | ---------
 Why3     | 1.8.2
 Alt-Ergo | 2.6.2
 CVC5     | 1.3.2
 Z3       | 4.15.2
 Coq      | 8.20.1

## Improvements

The main changes in this release concern the rewriting of Coq proofs to reflect
changes in WP (Frama-C).

- Logic and proofs:
  Renamed `RemovePartition` to `IndexOfNotEqual` and adjusted `remove` and
  `remove_copy3` implementations as well as the tutorial text accordingly.

- Verification support:
  Added new lemmas to improve verification rate:
  `AccumulateNext`, `InnerProductInit`, and `InnerProductNext`.

- Cleanup:
  Removed references to `count2` from the tutorial.

- Build system:
  Fixed and cleaned up Makefile targets.

## Open issues

The following warnings are mainly due to changes in the behavior and diagnostics
of WP (Frama-C) and will be addressed in a later revision of *ACSL by Example*.

- Missing explicit `terminates` / `exits` clauses:
  Function contracts are present but lack explicit `terminates` and/or `exits`
  clauses for functions without visible bodies; WP therefore generates default
  clauses.

- Pedantic assigns warning:
  An `assigns` clause is missing or too weak compared to the implementation,
  reported under `wp:pedantic-assigns`.

- Unsupported statement-level specification:
  A statement contract is present but currently ignored by WP due to lack of
  support.
