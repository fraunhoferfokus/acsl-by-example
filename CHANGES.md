
# Changes

This file documents user-visible changes and known limitations of released
snapshots of *ACSL by Example*.  It is intended to complement the stable overview
provided in `README.md`.

---

## Version 32.0.1  
(Targeting Frama-C 32.0 “Germanium”)

### Improvements

- Added `terminates` and `exits` clauses to all function contracts.

- Completed the `assigns` clauses of `stackinit` and `axiomsizeofinit`
  with explicit `\from` dependencies, clarifying the origin of assigned
  values and aligning the contracts with WP’s pedantic assigns checks.

- Replaced statement contracts in `pop_heap`, `partial_sort`,
  `selection_sort`, `insertion_sort`, and `merge` by assertions referring to
  an explicit ghost label, thereby making the proof obligations local to
  the respective loop bodies.

- Improved the description of non-mutating algorithms; removed `count2`
  and the inductively defined logic function `CountInd`.

- Improved the description of minimum and maximum algorithms.

- Improved the description of binary search algorithms and removed
  `binary_search2`.
