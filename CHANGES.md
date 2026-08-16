
# Changes

This file documents user-visible changes and known limitations of released
snapshots of *ACSL by Example*.  It is intended to complement the stable overview
provided in `README.md`.

---

## Version 33.0.0
(August 2026, targeting Frama-C 33.0 "Arsenic")

### New examples

- `find_last` returns the *last* occurrence of a value in a range and is thus
  the counterpart of `find`. It is not part of the C++ 17 draft standard; the
  C++ Standard Library provides it as one of the range algorithms introduced
  with the 2023 revision of the C++ standard.
- `all_of`, `any_of`, and `none_of` report whether a property holds for all,
  for some, or for no element of a range. Since the relevant properties are
  already available as ACSL predicates, each of their contracts consists of a
  single postcondition. None of the three algorithms performs a linear scan of
  its own: each delegates the search to `find` respectively `find_if_not` and
  merely inspects the returned index, so that no loop annotations are required.

### Improvements

- the epilogues of `push_heap` and `pop_heap` now state explicitly which parts
  of the array remain unchanged before relating the pre-state and the
  post-state by `ArrayUpdate`. A loop invariant of `pop_heap` that had become
  redundant was removed. As a result, `pop_heap` no longer requires an
  increased prover timeout, so that all examples of this book are now verified
  with the same timeout settings.
- restructured the methodology section of `Stack`. The three abstraction levels
  are now presented as such, weak type invariants are introduced as the means
  of delimiting the domain on which algebraic reasoning takes place, and
  *witnessing* is discussed separately as a way of performing relational
  reasoning in an otherwise function-centric verification framework. The
  methodology is presented in general form in Völlinger and Gerlach, *From
  Algebraic Data Types to Formally Verified Data Structures: The Stack Data
  Type* (submitted to SEFM 2026).
- the prover timeout stated in the section on verification settings of the
  report is now given relative to a named reference machine, since a timeout is
  only meaningful together with the hardware it refers to.
- completed the transition to the array slice notation begun in Version 32.0.2:
  it is now used in the descriptions of all algorithms and is defined in the
  section on arrays and ranges of the report rather than alongside the
  predicate `Equal`. Since ACSL offers no half-open range notation, annotations
  and the clauses quoted from them continue to use the closed form.
- reworked the build and verification infrastructure of the examples: proof
  results are now tracked with precise dependencies, the provers share a proof
  cache, and each directory documents its own targets.
