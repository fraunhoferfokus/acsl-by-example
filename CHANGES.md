
# Changes

This file documents user-visible changes and known limitations of released
snapshots of *ACSL by Example*.  It is intended to complement the stable overview
provided in `README.md`.

---

## Version 32.0.0  
(Targeting Frama-C 32.0 “Germanium”)

### Improvements

- **Adaptation to Frama-C/WP evolution**  
  The specifications and accompanying Coq proofs have been revised to reflect
  changes in the WP plugin and its generated proof obligations.

- **Renamed and clarified logical concepts**  
  The logic predicate `RemovePartition` has been renamed to
  `IndexOfNotEqual`.  The corresponding specifications, implementations
  (`remove`, `remove_copy3`), and tutorial text have been updated accordingly.

- **Additional supporting lemmas**  
  New lemmas have been introduced to improve proof automation and robustness,
  in particular:
  - `AccumulateNext`
  - `InnerProductInit`
  - `InnerProductNext`

- **Tutorial cleanup**  
  Obsolete references to `count2` have been removed from the report.

- **Build system fixes**  
  Minor corrections and cleanups have been applied to the Makefiles to ensure
  consistent verification runs with the current toolchain.

---

### Open issues

The following issues are known and mainly stem from changes in the behavior or
diagnostics of Frama-C/WP.  They do not affect the correctness of the examples
but may result in warnings during verification.

- **Missing explicit `terminates` / `exits` clauses**  
  Some function contracts omit explicit `terminates` and/or `exits` clauses.
  WP therefore inserts default clauses, which may lead to warnings.

- **Pedantic assigns warnings**  
  In a few cases, WP reports `wp:pedantic-assigns` warnings where the `assigns`
  clause is missing or weaker than the implementation.

- **Ignored statement-level specifications**  
  Certain statement contracts are currently ignored by WP and trigger
  informational warnings.

These issues are expected to be addressed in future revisions of
*ACSL by Example*.

