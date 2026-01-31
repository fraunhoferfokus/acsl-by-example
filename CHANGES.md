
# Changes

This file documents user-visible changes and known limitations of released
snapshots of *ACSL by Example*.  It is intended to complement the stable overview
provided in `README.md`.

---

## Version 32.0.2  
(Targeting Frama-C 32.0 “Germanium”)

### Improvements

**ACSL specifications and source code**
- Introduced the predicate `Rotate` and employed it systematically in the
  specification and verification of `rotatecopy`, `rotatei`, and
  `insertionsort`.
  - Added the lemma `RotateShift`.
  - Renamed `CircularShift_StrictLowerBound` to
    `RotateOneStrictLowerBound`.
  - Renamed `CircularShift_MultisetReorder` to
    `RotateOneMultisetReorder`.

**Changes in [ACSL by Example](https://github.com/fraunhoferfokus/acsl-by-example/blob/master/ACSL-by-Example.pdf)**
- Improved and expanded the descriptions of the algorithms in Parts 3–5.
- Updated and revised numerous figures.
- Introduced the slice notation `a[m..n)` in place of `a[m..n-1]`.
- Refined the presentation of the predicate `Unchanged` and clarified its
  relationship to the `assigns` clause.
- Revised the overall structure of the document.
- Updated the font packages used for the report.

