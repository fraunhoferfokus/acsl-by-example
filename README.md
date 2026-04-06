
# ACSL by Example

This repository contains version 32.0.3 of
[ACSL by Example](https://github.com/fraunhoferfokus/acsl-by-example/blob/master/ACSL-by-Example.pdf)
--- a curated collection of C functions and data types whose behavior has been
formally specified using **ACSL** (ANSI/ISO C Specification Language) and
formally verified with **Frama-C/WP**.

The material is intended as an outward-facing reference and tutorial for
deductive verification of C programs.  It accompanies the report
*ACSL by Example*, which provides the conceptual background, specification
patterns, and verification discussions for the examples contained here.

This version targets
[Frama-C 32.0 (Germanium)](https://www.frama-c.com/fc-versions/germanium.html)
and relies, among others, on the following software packages:

*Package* | *Version*
--------- | ---------
 Why3     | 1.8.2
 Alt-Ergo | 2.6.2
 CVC5     | 1.3.3
 Z3       | 4.15.2
 Coq      | 8.20.1

---

## Repository structure

- `ACSL-by-Example.pdf`  
  The main report.  It introduces the specification and verification methodology,
  explains the underlying ACSL patterns, and discusses the examples group by
  group, including remarks on proof structure and verification results.

- `StandardAlgorithms/`  
  The complete C source code of the examples, including ACSL annotations and
  verification artefacts.  
  This directory is provided as a **self-contained snapshot** of the internal
  development code base used to produce the examples discussed in the report.
  It is intended for reading, verification, and experimentation rather than
  incremental development.

- `StandardAlgorithms/subdirs.list`  
  The authoritative list of **example groups** and their ordering.

- `README.md`  
  This file.

- License and auxiliary configuration files.

---

## Example groups

The examples are organised into **groups**, not as an unstructured collection
of individual files.

- The groups are listed in `StandardAlgorithms/subdirs.list`.
- A short description, motivation, and discussion of each group is given in the
  corresponding chapters of `ACSL-by-Example.pdf`.

This README deliberately avoids duplicating the chapter-level descriptions from
the report and instead focuses on the overall structure of the repository.

---

## Intended use

This repository is intended for:

- learning and teaching ACSL and deductive verification with Frama-C/WP,
- studying specification idioms for common algorithmic patterns,
- experimenting with automated and interactive verification tools on
  realistic C code,
- serving as a stable reference collection of formally specified algorithms.

Readers are encouraged to consult the report alongside the source code, as the
report provides the conceptual structure and explanatory context.

---

## Getting started

A detailed description of the build and verification setup is intentionally
kept separate.

At a high level, working with the examples involves:

1. Installing a compatible Frama-C version with the WP plugin.
2. Ensuring suitable automatic provers (and optionally Coq) are available.
3. Selecting an example group via `StandardAlgorithms/subdirs.list`.
4. Running Frama-C/WP on the corresponding source files.
5. Inspecting proof results and, where applicable, interactive proofs.

Verification outcomes and methodological remarks are documented in the report.

---

## License

This repository is released under the **MIT License**.

