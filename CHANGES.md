
# Changes

This file documents user-visible changes and known limitations of released
snapshots of *ACSL by Example*.  It is intended to complement the stable overview
provided in `README.md`, and it is the complete record: every release from the
current one down to 4.2.0 is listed here, newest first.

---

## Version 33.0.1
(September 2026, targeting Frama-C 33.0 "Arsenic")

Most of the changes listed below were prepared with the help of AI coding
agents, chiefly Claude Code but also Codex. The agents proposed code,
annotations and prose; what to keep, and how to say it, was decided by us.
Every contract, proof and description was reviewed before it entered the
report, and every proof result reported here comes from an actual run of
Frama-C/WP. The responsibility for this release is ours.

### New examples

- `is_sorted_until` returns the length of the longest increasing prefix of an
  array and is thus to `is_sorted` what `is_heap_until` is to `is_heap`.
  `is_sorted` no longer scans the array itself but delegates to it; its
  contract is unchanged, and its proof obligations drop from 29 to 9.
- `merge_sort` splits an array into two halves, sorts each of them recursively,
  and joins the results with a single call to `merge`. It receives its working
  space as a third parameter, where `std::stable_sort` hides it the C++ 17
  draft standard. It is our first *recursive* example and thus the first whose
  contract carries a `decreases` clause. The new Lemmas
  `MultisetUnion_Reorder`, `Increasing_Unshift` and `MultisetReorder_Shift`
  carry what the recursive calls establish over to the postcondition of the
  whole array.
- `inplace_merge` merges two ordered ranges that lie next to each other in one
  array the C++ 17 draft standard and is presented in the section on
  `inplace_merge` of the report. Its implementation reuses the Lemmas
  `Rotate_Shift`, `RotateOne_StrictLowerBound` and `RotateOne_MultisetReorder`
  as they stand, so no new lemma was needed. The verification of
  `inplace_merge` is based on previous work of Denis Efremov.

### Implementations

- the heap algorithms now share a single descent. The new auxiliary function
  `heap_sift_down`, the section on `heap_sift_down` of the report, repairs a
  heap whose defect is confined to a single node, and the new predicates
  `HeapForest` and `HeapAncestor` state its precondition. `make_heap` applies
  it from the last internal node down to the root and so builds a heap in O(n)
  operations instead of the O(n log n) of repeated insertion with `push_heap`,
  while `pop_heap` repairs its prefix by a single call instead of a copy of the
  same descent and its proof shrinks from 189 proof obligations to 104. Both
  contracts are unchanged. These implementations go back to a pull request by
  Adam Berger (addaon), which we merged and modified.
- the assertions that follow the swap in `bubble_sort`'s inner loop now stand
  in front of the one that needs them, in `ArraySwap`'s own order, and the
  range that was not stated at all raises the proof obligations of the example
  from 109 to 110. The epilogues of `push_heap` and `pop_heap` were given the
  same treatment in Version 33.0.0.

### Contracts

- the postcondition `last` of `is_heap_until` no longer quantifies over all
  longer prefixes of the array. It denies the heap property of the shortest
  prefix that exceeds the returned index, from which Lemma `Heap_Shrink`
  carries the failure to every longer one; a loop invariant that this made
  redundant was removed. The new Lemma `Increasing_Shrink` serves
  `is_sorted_until` in the same way.
- the postcondition of `merge` now states what the algorithm produces, and not
  merely that the result is ordered. The new predicate `MultisetUnion` relates
  three arrays in one program state and, together with `increasing`, determines
  the output uniquely. This settles the first item of the open issue on the
  completeness of `merge`'s postcondition; the two remaining items concern
  stability and stay open.

### ACSL definitions

- the predicate `Partition` now takes the segment it refers to as an explicit
  pair of outer indices, with the position of the split between them, in the
  same way as `Increasing`, `Unchanged` and `Rotate`. The former two-index form
  remains available as the abbreviation of the case where the segment starts at
  0, so that the contract of `partial_sort` is unchanged.
- the predicates `SomeEqual` and `NoneEqual`, and likewise `AllEqual` and
  `SomeNotEqual`, are now related by a single equivalence each: the new Lemmas
  `NoneEqual_SomeEqual` and `SomeNotEqual_AllEqual` replace the pairs that
  stated the halves of one `<==>`, in the form that `LessOrEqual_Less` already
  uses for the relational operators. Every example that includes one of the two
  definitions has one goal fewer.
- `MultisetRetainRest` now carries two lemmas of its own, which state that the
  predicate survives a stretch in which the array does not change, once before
  and once after the temporary change. The corresponding lemmas of
  `MultisetParity` now reduce to the two, and none of them is near the prover
  timeout any more. `push_heap` and `heap_sift_down`, the two examples that
  include the definition, have two proof obligations more.
- the labels of ACSL annotations now follow one vocabulary: `bounds` is
  reserved for the predicates of that name, `bound` denotes a plain range,
  `index` a relation between indices, and the invariants of `search`,
  `search_n` and `find_end` say `no_match` where their contracts do. In
  `selection_sort` two loop invariants shared the same label, and a loop
  invariant of `find_last` that a neighbouring one already implied was removed.

### Verification

- the specifications are now searched for contradictions. A smoke test of
  Frama-C/WP asks whether `false` follows from a precondition, a behaviour
  assumption or a loop invariant; no contradiction was found. the section on
  the consistency of the specifications of the report describes what such a
  search can and cannot show.
- `rewrite_array_unchanged` and `rewrite_array_nothing` now take part in the
  verification run, without being examples in their own right. The two files of
  the section on the predicate `Unchanged` of the report make a point about
  `assigns` rather than compute anything, and the contract of
  `rewrite_array_nothing` is deliberately incorrect; each is now checked
  against the outcome it is meant to have, so that a counterexample that
  quietly began to prove would not pass unnoticed.
- the list of Frama-C options in the section on verification settings of the
  report now matches the command line that produced the results of this
  release. It had omitted `-wp-split`, which decides how a proof obligation is
  decomposed and therefore how many verification conditions each example has;
  `-no-warn-unaligned-pointer` and `-rte-no-pointer-call` were added as well.
- the proof obligations that no automatic prover can discharge are now named.
  The result tables count them per algorithm; the table in the section on the
  lemmas verified with Coq of the report lists the 52 ACSL lemmas they belong
  to, with the listing that shows each and the number of examples that carry
  it, and says why every one of them is a lemma. A comparable table was part of
  the report between versions 14.1.0 and 17.1.0.

### Descriptions

- the agreement of the prose with the listings is now checked mechanically, and
  the descriptions that had drifted are again phrased in the terms of the code,
  among them the loop invariants of `remove_copy3` and `partial_sum`, the
  generator state of `shuffle` and the parameter order of `search_n`.
- the section on `remove_copy3` of the report now says why
  `IndexOfNotEqual_Core` states three properties of the partitioning sequence
  in a single lemma: they are established by one induction on the rank k whose
  hypothesis has to supply all of them at once. The Coq script that carries the
  induction names its facts and records where each conjunct is used.
- the terms *array* and *range* are no longer used interchangeably: the section
  on arrays and ranges of the report calls the region described by a pointer
  and a length an array and reserves *range* for a contiguous part of one.
- the chapter on sorting says how its algorithms stand to one another: the
  overview is grouped, the section on the common contract records which five
  algorithms carry it and how the other five depart from it, `merge_sort` says
  why it keeps its auxiliary array rather than merging in place, and
  `insertion_sort` and `inplace_merge` point at each other.
- the report prints only the release notes of the version it is; the complete
  record of all releases is the file `CHANGES.md` of the repository, which is
  generated from these notes.

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

## Version 32.0.3
(April 2026, targeting Frama-C 32.0 "Germanium")

### New examples

None.

### Improvements

- refactoring of example `Stack`. The new version shifts from a
  procedure-oriented verification workflow to a conceptually structured,
  multi-level methodology with a strong emphasis on observational equality,
  well-definedness, and modular reasoning.
  - Introduction of a clear three-level methodology separating abstract stack
    axioms, logical specifications, and implementation.
  - Stronger emphasis on observational equality of stacks, including its role
    as an equivalence relation and its use in reasoning.
  - Systematic treatment of well-definedness of stack functions via dedicated
    witnesses, with a clear separation from axiom verification.
  - Reorganization of the verification flow: operations, then axioms, then
    well-definedness.
  - Simplification and clarification of witness specifications, including
    omission of low-level clauses for readability.
  - Improved modularization of the logical interface of `Stack` and clearer
    separation between representation and specification.
- removed the axiomatic blocks in logic definitions.
- the third version of `Equal` is now an explicit expansion of the previously
  delegated definition, with the universal quantification written out directly.
- predicate `Reverse` now identifies the second range by its one-past-the-end
  index.
- fixed wrong argument in the first version of `Rotate`.
- simplified the function `make_pair`.
- added figures to aide the description of the predicate `Reverse` and the
  algorithms `reverse_copy` and `reverse`.
- improved the description of the implementation and verification of `rotate`.
- expanded description of the specification of `clamp`.
- fixed misplaced LaTeX labels for ACSL listings.

## Version 32.0.2
(January 2026, targeting Frama-C 32.0 "Germanium")

### New examples

None.

### Improvements

- introduced the predicate `Rotate` and employed it systematically in the
  formal specification and verification of `rotate_copy`, `rotate`, and
  `insertion_sort`:
  - added the lemma `Rotate_Shift`,
  - renamed `CircularShift_StrictLowerBound` to `RotateOne_StrictLowerBound`,
  - renamed `CircularShift_MultisetReorder` to `RotateOne_MultisetReorder`.
- improved and expanded the descriptions of the algorithms in Parts 3--5.
- updated and revised numerous figures.
- introduced the slice notation a[m..n) in place of the previous notation
  `a[m..n-1]`.
- refined the presentation of the predicate `Unchanged` and clarified its
  relationship to the `assigns` clause.
- revised the overall structure of the document, strengthening the role of
  parts as the primary organizational units.
- updated the font packages used for the report.

## Version 32.0.1
(January 2026, targeting Frama-C 32.0 "Germanium")

### New examples

None.

### Improvements

- Added `terminates` and `exits` clauses to all function contracts.
- Completed the `assigns` clauses of `stack_init` and `axiom_size_of_init` with
  explicit `from` dependencies, clarifying the origin of assigned values and
  aligning the contracts with Frama-C/WP’s pedantic assigns checks.
- Replaced statement contracts in `pop_heap`, `partial_sort`, `selection_sort`,
  `insertion_sort`, and `merge` by assertions referring to an explicit ghost
  label, thereby making the proof obligations local to the respective loop
  bodies.
- Improved the description of nonmutating algorithms; removed `count2` and the
  inductively defined logic function `CountInd`.
- Improved the description of minimum and maximum algorithms.
- Improved the description of binary search algorithms and removed
  `binary_search2`.

## Version 32.0.0
(December 2025, targeting Frama-C 32.0 "Germanium")

The main changes in this release concern the rewriting of Coq proofs to reflect
changes in Frama-C/WP.

### New examples

None.

### Improvements

- Logic and proofs: rename `RemovePartition` to `IndexOfNotEqual` and adjust
  `remove` and `remove_copy3` implementations and tutorial text accordingly.
- Add new lemmas to improve verification rate: `Accumulate_Next`,
  `InnerProduct_Init` and `InnerProduct_Next`.
- Cleanup: remove references to `count2` from tutorial.
- Build system: fix and clean up Makefile targets.

### Known warnings

- **Missing explicit `terminates` / `exits` clauses** Function contracts are
  present, but lack explicit `terminates` and/or `exits` clauses for functions
  without visible bodies; WP therefore generates default clauses.
- **Pedantic assigns warning** An `assigns` clause is missing or too weak
  compared to the implementation, reported under `wp:pedantic-assigns`.
- **Unsupported statement-level specification** A statement contract is present
  but currently ignored by WP due to lack of support.

## Version 22.0.0
(November 2020, targeting Frama-C 22.1 "Titanium")

Note that all automatic provers use the Why3 interface. However, the
interactive prover Coq still relies on the native interface provided by
Frama-C/WP.

### New examples

None.

### Improvements

Updated to Coq 8.12.1.

### Open issues

- The contract of algorithm `merge` does not handle the reordering of the
  involved arrays.

## Version 21.1.1
(September 2020, targeting Frama-C 21.1 "Scandium")

Note that all automatic provers use the Why3 interface. However, the
interactive prover Coq still relies on the native interface provided by
Frama-C/WP.

### New examples

None.

### Improvements

- general changes
  - disable CVC3 and switch back to Z3 `4.8.6`
  - refactor Coq proofs
  - reduce general timeout to 1s (Coq timeout 5s)
- improve loop invariants of `remove_copy3` and `remove` to reduce timeout
- add lemma `AdjacentDifference_InverseBounds` to reduce timeout of
  `adjacent_difference_inv` robust
- add lemmas `Count_Single`, `Count_Single_Bounds`, `Count_Single_Shift` and
  `Count_Cut`
- heap algorithms
  - rework `push_heap` and add more assertions to reduce timeout
  - rework `pop_heap` and finally verify property `reorder`
  - add predicates `ArrayUpdate`, `MultisetParity`, `MultisetUpdate` and
    supporting lemmas
  - remove predicate `PushHeapAdjust` and accompanying lemmas
  - rename `heap_child_max` to `heap_child` and improve both contract and
    implementation
  - add lemma `HeapParent_Zero`
- sorting and reordering
  - rework contract and annotations of merge
  - no need more for option `-wp-split`
  - add lemma `WeaklyIncreasing_Shrink`
  - add lemma `WeaklyIncreasing_Unchanged`
  - add more annotations to `bubble_sort` to reduce timeout
  - add lemma `MultisetSwap_FrontMiddle`

### Open issues

- The contract of algorithm `merge` does not handle the reordering of the
  involved arrays.

### Renaming of ACSL definitions

- rename suffix `_Read` to `_Unchanged` in names of lemmas

## Version 21.1.0
(July 2020, targeting Frama-C 21.1 "Scandium")

Note that all automatic provers use the Why3 interface. However, the
interactive prover Coq still relies on the native interface provided by
Frama-C/WP.

### New examples

None.

### Improvements

- Improve many code annotations in order to maintain the verification rate and
  to reduce timeout values.
- Use predicate `WeaklyIncreasing` instead of `Increasing` in the assertions
  and invariants of sorting algorithms. This allows the removal of lemma
  `IncreasingUpperBound`.
- Add Coq to parallel verification
- Replace an ACSL lemma on integer division by a Coq lemma in driver.
- `remove_copy` and `remove`
  - Remove logic helper function `NextNotEqual` for `RemovePartition` which
    served as a workaround in Frama-C 20.
  - Remove lemma `RemovePartition_StrictlyIncreasing`.
  - Make the definition of predicate `Remove` more flexible.
  - Remove lemma `Remove_Update`.
- heap algorithms
  - Simplify definition of predicates `MultisetRetainRest` and `MultisetMinus`.
  - Add predicate `PushHeapAdjust`.
  - Add lemmas `PushHeapAdjust_Init` and `PushHeapAdjust_Finish`.
  - Rename lemma `MultisetPushHeapRetain` to `PushHeapAdjust_Retain`.
  - Add predicate `HeapCompatible` and lemmas `Heap_Shrink`, `Heap_Unchanged`
    and `Heap_Update`.
  - Improve annotations of `push_heap` and `pop_heap`.
  - Remove predicate `HeapChildMax` and simplify the contract of
    `heap_child_max`.
- Remove lemma `SwappedInside_Preserve` which was of limited usefulness.
- Add lemmas `Accumulate_Init`, `AccumulateBounds_Read` and
  `Accumulate_Read_Shrink`, which were suggested by Allan Blanchard, in to
  simplify the verification of `partial_sum` and `adjacent_difference_inv`.
- Add lemmas `Unchanged_Symmetric` and `MultisetUnchanged_Symmetric`.

### Open issues

- `pop_heap`
- `merge`

## Version 20.0.2
(April 2020, targeting Frama-C 20.0 "Calcium")

Note that all automatic provers use the Why3 interface. However, the
interactive prover Coq still relies on the native interface provided by
Frama-C/WP.

### New examples

- Add examples `find4` and `find5` that verify the equivalence of the contracts
  of `find2` and `find3`.
- Add example `find_if_not`.

### Improvements

- Add indices for examples and logic definitions.
- Re-add results of running all provers in parallel. Thanks to Allan Blanchard
  for explaining how Frama-C/WP's *session* mechanism can be used in the
  implementation.
- Fix a ghost label in `partial_sort`. Thanks to Virgile Prevosto for pointing
  out stricter checks in upcoming releases of Frama-C.
- Reduce very long verification times of several examples.
  - Add assertion `unchanged` to empty else branch of `remove_copy3`.
  - Add assertion `reorder` to empty else branch of `shuffle`.
  - Rewrite assertion `update` of `remove`.
  - Add another assertion `heap` to `push_heap`.
- Remove chapter on `unique_copy` because on its reliance on axioms. Moreover,
  the main ideas are already extensively discussed in the sections on
  `remove_copy` and `remove`.
- Verify properties of operator `<` within example `clamp`.
- Improve admitted Coq proof of `Reorder_Match`.
- Fix misplaced arrow in figure of `equal_range` algorithm

### Open issues

- `pop_heap` (property `reorder`)
- `merge` (property `reorder`)
- `Reorder_Match`

## Version 20.0.1
(March 2020, targeting Frama-C 20.0 "Calcium")

Note that all automatic provers use the Why3 interface. However, the
interactive prover Coq still relies on the native interface provided by
Frama-C/WP.

### New examples

- add a third version of `find` that is specified using the new logic function
  `Find`

### Improvements

- improve text in many places
- improve specification of `remove_copy` and `remove`
  - provide an explicit definition of `RemovePartition` that allows to replace
    axioms by lemmas
  - rename predicate `ConstantRange` to `AllEqual` and add its negation
    `SomeNotEqual`
  - add logic functions `CountNotEqual` and `FindNotEqual`
- place all logic definitions in `axiomatic` blocks to better control generated
  names
- make names of ACSL predicates, functions and lemmas more uniform and place
  them together in files where appropriate
- among the renamed ACSL entities are
  - rename predicate `HasValue` to `SomeEqual` and add its negation `NoneEqual`
  - rename lemma `HasValueImpliesPositiveCount` to `SomeEqualCount`
  - rename lemma `PositiveCountImpliesHasValue` to `Count_SomeEqual`
  - rename `RotatePreservesStrictLowerBound` to
    `CircularShift_StrictLowerBound`
  - rename `RotateImpliesMultisetUnchanged` to `CircularShift_MultisetReorder`

### Open issues

- `pop_heap`
- `Reorder_Match`

## Version 20.0.0
(Calcium, December 2019)

Note that all automatic provers are use the Why3 interface. In other words, we
do not use anymore the native interface for Alt-Ergo.

### New examples

- add `bubble_sort`

### Improvements

- remove Why3 and Alt-Ergo lemmas from driver
- switch from memory model 'Typed+Ref' to 'Typed'
- the E theorem prover is not yet supported by this version of Frama-C
- no results on parallel verification are reported in this release
- rewrite `random_shuffle` to `shuffle`
  - adapt signature of `random_number`
  - add auxiliary function `random_init`
- replace, where applicable, ghost labels by loop labels or statement labels
- remove lemma `SwapImpliesMultisetUnchanged` by using predicate
  `SwappedInside` and its related lemmas
- improve specification and verification rate of numeric algorithms
  - resolve overloaded version of `Accumulate` into `AccumulateDefault`
  - resolve overloaded version of `AccumulateBounds` into
    `AccumulateDefaultBounds`
  - improve definition of predicate `PartialSum`
  - add lemmas `Difference_Zero` and `Difference_Next`
  - add predicate `DefaultBounds`
- add assigns in behaviors of maxmin and nonmutating algorithms
  - `find`, `find2`, `find_first_of`, `adjacent_find`, `mismatch`, `search`,
    `find_end`
  - `max_element`, `max_element2`, `min_element`, `minmax_element`
- rename predicate `Sorted` to `Increasing`; also rename related logic names
  - rename `EqualRangesPreservesSorted` → `EqualRangesPreservesIncreasing`
  - rename `SortedUpperBound` → `IncreasingUpperBound`
  - rename `WeaklySortedAddElement` → `WeaklyIncreasingAddElement`
  - rename `WeaklySortedShift` → `WeaklyIncreasingShift`
  - rename `EqualRangesWeaklySorted` → `EqualRangesWeaklyIncreasing`
  - rename `WeaklySortedJoin` → `WeaklyIncreasingJoin`
  - rename `WeaklySortedLemmas` → `WeaklyIncreasingLemmas`
  - rename `SortedIFFWeaklySorted` → `IncreasingIFFWeaklyIncreasing`
  - rename `SortedImpliesWeaklySorted` → `IncreasingImpliesWeaklyIncreasing`
  - rename `WeaklySortedImpliesSorted` → `WeaklyIncreasingImpliesIncreasing`
  - rename `WeaklySorted` → `WeaklyIncreasing`
  - rename `SortedShift` → `Increasing_Shift`
- remove lemma `SortedDownIsHeap`

### Open issues

- `adjacent_difference_inv`
- `pop_heap`
- `random_number`
- `ReorderImpliesMatch`

## Version 19.1.0
(Potassium, October 2019)

Note that all automatic provers are use the Why3 interface. In other words, we
do not use anymore the native interface for Alt-Ergo.

### Improvements

- Rename arguments of `search` and `find_end` and improve also the description
  of these algorithms.
- Rename and reorder arguments of `search_n`, make the verification more robust
  and improve its description.
- Make verification of property `size` of `remove_copy2` more robust.
- Explain role of lemma `RemoveImpliesNotHasValue` in `remove_copy3` and
  `remove`.
- Simplify definition of `RemoveSize` and `RemovePartition`.
- Make verification of property `reorder` of `partial_sort` more robust.
- Strengthen precondition of `replace_copy`.
- Rename lemma `random_number_modulo` into `RandomNumberModulo`.
- Differentiate between properties `unique` and `solitary` for `unique_copy`
  examples.
- Simplify the implementation of `is_heap` by calling the new function
  `is_heap_until`.
- Replace remaining instances of label `Pre` in contracts by `Old`.
- Unify use of `Unchanged` predicate for mutating algorithms.

### New examples

- Add the algorithm `clamp` which "clips" a value between a pair of boundary
  values.
- Add the algorithm `minmax_element` and improve description of other
  algorithms related to finding minimum and maximum values.
- Add new example `is_heap_until` that generalizes `is_heap`.
- The following examples are not new since they were implicitly used as helper
  functions for other examples. They are now explicitly listed as examples.
  - `make_pair`
  - `random_number`
  - `heap_parent`
  - `heap_child_max` (formerly known as `heap_maximum_child`)

### Open issues

- `adjacent_difference_inv`
- `partial_sum_inv`
- `pop_heap`
- `ReorderImpliesMatch`

## Version 19.0.0
(Potassium, June 2019)

- Structure of document
  - The document is now structured into several parts.
  - The chapter on classic sorting algorithms has been merged into the chapter
    on sorting.
  - The various variants of `unique_copy` are now grouped into a separate
    chapter.
- Fix various inconsistencies
  - Change the return types of the logic functions `Accumulate`, `Difference`,
    `Capacity`, `Size`, `Top` from bounded one (e.g., `value_type`,
    `size_type`) to integer. A combination of bounded type for a logic function
    with an arithmetic operations in the logical definitions may lead to
    inconsistency. This fixes the inconsistencies in the `accumulate`, `stack`
    and `stack_wd` examples.
  - Fix an inconsistency in `DifferenceRead` axiom: restriction on the array
    size added to premises.
- Various improvements
  - An important change is the rewriting of the implicit, *axiomatic*
    definitions of `Accumulate`, `Count`, `Difference`, `InnerProduct` and
    `UniqueSize` logic functions to explicit, *recursive* ones. Accordingly,
    all axioms in the respective examples have been rewritten as lemmas.
  - Generalize `CountSectionMonotonic`, `UnchangedSection` lemmas: remove
    restriction on lower bound for the range.
  - Fix typo in postcondition of `find`.
  - Rewrite specifications of `remove_copy` and `remove` examples.
  - Rename predicate `RemoveCount` to `RemoveSize`.
  - Gather all versions of `MultisetRetainRest` in section on `push_heap`.
  - Add another figure to highlight simple contract for `unique_copy`.
  - Adapt Coq proofs to the fact that the `Z` scope is not available by
    default.
- New examples
  - Add `count2` example with an inductive predicate instead of a logic
    function in `count`.
  - Add `merge` example.
- Infrastructure
  - Travis-CI configuration for the GitHub repository added as an illustrative
    example of how the verification results could be reproduced.
  - Add support for Frama-C/AstraVer plugin.

## Version 18.0.0
(Argon, December 2018)

- Replace the links to the (now abandoned) original site of *Standard Template
  Library* (STL) by references to the C++ standard.
- Add new algorithm `unique_copy` (two versions).
- Add another assertion `half` for `reverse`.
- Add two overloaded versions of predicate `ConstantRange` and use them for the
  algorithms `fill` and `unique_copy`, respectively.

## Version 17.1.0
(Chlorine, July 2018)

The exact version number of Frama-C originally was Chlorine-20180502. This
version number was changed in October 2018 to 17.1

- Slightly change the definition of predicate `HasEqualNeighbors` and its use
  in the specification of `adjacent_find`.
- Remove the algorithm `remove` and the more elaborate version of
  `remove_copy`. We are currently working on new specifications of these
  algorithms.
- Adapt some Coq proofs related to the logic function `Count` in order to
  reflect changes in output of Frama-C/WP.
- Remove table on ACSL lemmas that had to be proved by Coq.

## Version 16.1.1
(Sulfur, March 2018)

- fix several errors reported by Aaron Rocha, including,
  - fix an error in figure for `upper_bound` algorithms
- fix merging of contracts in second version of `binary_search`
- improve and justify the `retain` annotations of in the implementation of
  `remove`
- Alt-Ergo is now directly called in the parallel setting (instead of going
  through Why3) to be compatible with the sequential setting
- add a third assertion `reorder` in the `random_shuffle` body to keep
  verification rate at 100% after prover upgrade

## Version 16.1.0
(Sulfur, December 2017)

- special thanks to Aaron Rocha who provided various improvements for Chapters
  *Nonmutating algorithms*, *Minimum and maximum algorithms*, and *Binary
  search algorithms*
- improve some mutating algorithms
  - add more assertions to `reverse` to reduce reliance on CVC3
  - improve structure and ACSL annotations of `remove_copy` and `remove`
    - add overloaded version of predicate `MultisetRetainRest`
    - add lemma `HasValueImpliesPositiveCount`
    - add lemma `PositiveCountImpliesHasValue`
    - remove lemma `HasValueShiftInversion`
    - remove lemma `HasValueCountInversion`
  - add custom lemma `random_number_modulo` for `random_shuffle`
- add new Chapter *Sorting Algorithms* with more algorithms related to sorting
  - add algorithm `is_sorted` including predicate `WeaklyIncreasing`
    - add lemma `IncreasingImpliesWeaklyIncreasing`
    - add lemma `WeaklyIncreasingImpliesIncreasing`
  - add algorithm `partial_sort` including predicate `Partition`
    - add lemma `ReorderImpliesMatch`
    - add lemma `ReorderPreservesUpperBound`
    - add lemma `ReorderPreservesLowerBound`
    - add lemma `PartialReorderPreservesLowerBounds`
    - add lemma `SwappedInside`
    - add lemma `SwappedInsideMultisetUnchanged`
    - add lemma `SwappedInsidePreservesMultisetUnchanged`
- improve various lemmas
  - rename lemma `SortedUp` to `IncreasingUpperBound`
  - generalize lemma `UnchangedSection`
  - refactor lemma `HeapBounds` into `C_Division_Two`

## Version 15.1.2
(Phosphorus, October 2017)

- fix several typos reported by `seniorlackey@github` (thanks a lot!)
- add a new chapter on classic sorting algorithms which comprises
  - `selection_sort` including lemma `SwapImpliesMultisetUnchanged`
  - `insertion_sort` including lemmas
    - `RotatePreservesStrictLowerBound`
    - `RotateImpliesMultisetUnchanged`
    - `EqualRangesPreservesIncreasing`
    - `EqualRangesPreservesCount`
  - `heap_sort`
- heap algorithms
  - remove length requirements in `pop_heap`, `sort_heap`, `make_heap`, and
    `heap_sort`
    - introduce `SIZE_TYPE_MAX` to catch border cases in ACSL and C
  - improve description of `pop_heap`
    - add predicate `HeapChildMax`
    - provide the auxiliary function `heap_child_max`
    - the postcondition `reorder` is still not verified
  - improve description of `push_heap`
  - other, minor improvements
    - add auxiliary function `heap_parent`
    - add predicate `SortedDown` and lemma `SortedDownIsHeap`
    - add lemmas `HeapParentChild` and `HeapChilds`
    - add lemmas `HeapParentBounds` and `HeapChildBounds`

## Version 15.1.1
(Phosphorus, September 2017)

- add ensures clause to default behavior of the following algorithms
  - `find`, `find_first_of`, `adjacent_find`, `mismatch`, `search`, `search_n`,
    `find_end`
  - `max_element`, `min_element`
- rewrite axiomatic definitions to ensure disjoint guards which is better
  suited for E-ACSL
  - concerns the axiomatic definitions of `Count`, `Accumulate`, `InnerProduct`
    and `Difference`
  - some Coq proofs related to `Count` had to be adapted as well
- shorten names of some auxiliary algorithms
  - `adjacent_difference_inverse` → `adjacent_difference_inv`
  - `partial_sum_inverse` → `partial_sum_inv`
- heap algorithms
  - fix a typo in Figure *Underlying array representation of the heap*
  - fix a typo in Figure *Array after the call of `sort_heap`*
  - explain that there can be multiple representations of an array as a heap
  - add a version of `pop_heap` that is, however, not completely verified

## Version 15.1.0
(Phosphorus, June 2017)

- The verification results are now part of the appendix.
- Fix an error in the specification of the well-definition of `stack_size`.
- This release of Frama-C/WP could not discharge some of our assertions of
  `push_heap`. We therefore have completely rewritten the annotations and also
  tweaked the implementation of `push_heap`. We also added some new predicates
  and lemmas to maintain a concise specification that can easily be verified by
  automatic provers.
  - add predicate `MultisetAdd` and lemma `MultisetAdd_Distinct`
  - add predicate `MultisetMinus` and lemma `MultisetMinus_Distinct`
  - add predicate `MultisetRetain` and lemma `MultisetPushHeapRetain`
  - provide an additional version of predicate `MultisetRetainRest`
  - and lemma `MultisetPushHeapClosure`

## Version 14.1.1
(Silicon, April 2017)

- changes in verification infrastructure
  - add verification results for the case where each proof obligation is
    submitted to all automatic theorem provers
- changes in algorithms
  - simplify loop invariants of `search_n` and improve description
  - rename predicate `CountOneHit` to `CountHit`
  - rename predicate `CountOneMiss` to `CountMiss`
  - rewrite predicates `EqualRanges` and `Reverse` in order to simplify the
    task for automatic theorem provers
  - remove lemmas on `Reverse` that were necessary for `rotate` but are not
    needed anymore
  - rename predicate `Valid(Stack)` to `Invariant(Stack)` and remove `valid`
    from `Invariant(Stack)`
  - add a simple random number generator to `random_shuffle` and verify it
- fix an inconsistency in the axioms for `Count` (thanks to Denis Efremov for
  reporting this issue)
  - add more guards to axioms `CountSectionHit` and `CountSectionMiss`
  - add corresponding guards to lemmas
    - `CountSectionOne`, `CountHit`, `CountMiss` and `CountOne`
    - `RemoveCountHit` and `RemoveCountMiss`
  - add lemma `Unchanged_Shift` and add more assertions to `remove` in order to
    simplify the task for automatic theorem provers

## Version 14.1.0
(Silicon, January 2017)

- use label `Old` instead of `Pre` in function contracts
- add algorithm `rotate`
- rewrite definition of predicates `EqualRanges` and `Reverse` and provide more
  overloaded versions
- add figures for algorithms `rotate` and `replace_copy`
- update figure for predicate `Reverse`
- update Coq proofs and add a table with more information on the ACSL lemmas
  that had to be verified with Coq

## Version 13.1.1
(Aluminium, November 2016)

- improve layout of tables of verification results
- use two additional automatic theorem provers (CVC3 and E)
- nonmutating algorithms
  - add algorithm `find_end`
  - add definition of predicate `HasSubRange` on subranges
  - add definition of predicate `EqualRanges` on subranges
  - rename lemma `HasSubRange_fit_size` to `HasSubRangeSize`
  - rename lemma `HasConstantSubRange_fit_size` to `HasSubRangeSize`
  - rename logic function `CountSection` to `Count` (using overloading in ACSL)
  - add lemma `HasValueCountInversion`
  - add lemma `HasValueShiftInversion`
  - add lemma `Count_Shift`
- mutating algorithms
  - add algorithm `copy_backward`
  - relax precondition on separation of `copy`, `replace_copy` and
    `remove_copy`
  - provide a more sophisticated implementation of `remove`
  - re-introduce a second version of `remove_copy` that also specifies the
    *stability* of the algorithm
  - add algorithm `random_shuffle`

## Version 13.1.0
(Aluminium, August 2016)

The most notable changes of this version are the re-introduction of heap
algorithms in Chapter *Heap Algorithms*. This new description of heap
algorithms is based to a large extend on the bachelor thesis of one of the
authors (Timon Lapawczyk, *Formale Verifikation von Heap-Algorithmen mit
Frama-C*, Humboldt-Universität zu Berlin, 2016).

- provide names ("labels") for more ACSL annotations
- nonmutating algorithms
  - reorder and improve description in chapter on nonmutating algorithms
  - add more figures to describe algorithms
  - add nonmutating algorithm `search_n`
  - rewrite logic function `Count` with new logic function `CountSection`
  - move lemmas `Count_Bounds` and `CountMonotonic` to separate files
  - use `integer` instead of `size_type` in `HasSubRange`
  - change index computation in `HasEqualNeighbors`
- maximum and minimum algorithms
  - isolate predicate `ConstantRange` from predicates on lower and upper bounds
  - fix typo in precondition of first version of `max_element`
- binary search algorithms
  - add version `Sorted` for subranges
  - add second (more efficient) version of `equal_range`
    - add lemmas `SortedShift`, `LowerBound_Shift`, `StrictLowerBound_Shift`,
      `UpperBound_Shift` and `StrictUpperBound_Shift` to support the automatic
      verification of this version of `equal_range`
  - add figures to binary search algorithms and improve description
- mutating algorithms
  - greatly reduce the number of assertions needed to verify the first version
    `remove_copy`
  - temporarily remove the second version of `remove_copy` which also specified
    the *stability* of the algorithm
  - add `remove`, an in-place variant of `remove_copy`
  - rename predicate `RetainAllButOne` to `MultisetRetainRest`
- re-introduce chapter on heap algorithms
  - includes the heap algorithms `is_heap`, `push_heap`, `make_heap` and
    `sort_heap`
  - for `pop_heap` only a function contract is provided in this version
  - add lemma `SortedUp` to support verification of `sort_heap`
  - add several lemmas to combine the predicates `Unchanged` and
    `MultisetUnchanged`

## Version 12.1.0
(Magnesium, February 2016)

A main goal of this release is to reduce the number of proof obligations that
cannot be verified automatically and therefore must be tackled by an
interactive theorem prover such as Coq. To this end, we analyzed the proof
obligations (often using Coq) and devised additional assertions or ACSL lemmas
to guide the automatic provers. Often we succeeded in enabling automatic
provers to discharge the concerned obligations. Specifically, whereas the
previous version 11.1.1 of *ACSL by Example* listed *nine* proof obligations
that could only be discharged with Coq, the document at hand (version 12.1.0)
only counts *five* such obligations. Moreover, all these remaining proof
obligations are associated to ACSL lemmas, which are usually easier to tackle
with Coq than proof obligations directly related to the C code. The reason for
this is that ACSL lemmas usually have a much smaller set of hypotheses. Adding
assertions and lemmas also helps to alleviate a problem in Frama-C/WP Magnesium
and Sodium where prover processes are not properly terminated. (See
https://bts.frama-c.com/view.php?id=2154) Left-over "zombie processes" lead to
a deterioration of machine performance which sometimes results in unpredictable
verification results.

- mutating algorithms
  - simplify annotations of `replace_copy` and add new algorithm `replace`
    - add predicate `Replace` to write more compact post conditions and loops
      invariants
  - add several lemmas for predicate `Unchanged` and use predicate `Unchanged`
    in postconditions of mutating and numeric algorithms
  - simplify annotations of `reverse`
    - rename `Reversed` to `Reverse` (again) and provide another overloaded
      version
    - add figure to support description of the `Reverse` predicate
  - changes regarding `remove_copy`
    - rename `PreserveCount` to `RetainAllButOne`
    - rename `StableRemove` to `RemoveMapping`
    - add statement contracts for both versions of `remove_copy` such that only
      ACSL lemmas require Coq proofs
- numeric algorithms
  - define limits `VALUE_TYPE_MIN` and `VALUE_TYPE_MAX`
  - simplify specification of `iota` by using new logic function `Iota`
  - simplify implementation of `accumulate`
    - add overloaded predicates `AccumulateBounds`
    - add lemmas `AccumulateDefault0`, `AccumulateDefault1`,
      `AccumulateDefaultNext`, and `AccumulateDefault_Read`
  - simplify implementation of `inner_product`
    - add predicates `ProductBounds` and `InnerProductBounds`
  - enable automatic verification of `partial_sum`
    - add lemmas `PartialSumSection`, `PartialSumUnchanged`, `PartialSum_Step`,
      and `PartialSumStep2` to automatically discharge loop invariants
  - enable automatic verification of `adjacent_difference`
    - add logic function `Difference` and predicate `AdjacentDifference`
    - add predicate `AdjacentDifferenceBounds`
    - add lemmas `AdjacentDifference_Step` and `AdjacentDifference_Section` to
      automatically discharge proof obligation
  - add two auxiliary functions `partial_sum_inverse` and
    `adjacent_difference_inverse` in order to verify that `partial_sum` and
    `adjacent_difference` are inverse to each other
    - add lemmas `PartialSumInverse` and `AdjacentDifferenceInverse` to support
      the automatic verification of the auxiliary functions
- stack functions
  - add lemma `StackPushEqual` to enable the automatic verification of the
    well-definition of `stack_push`

## Version 11.1.1
(Sodium, June 2015)

- add Chapter on numeric algorithms
  - move `iota` algorithm to numeric algorithms (the section on `iota` of the
    report)
  - add `accumulate` algorithm (the section on `accumulate` of the report)
  - add `inner_product` algorithm (the section on `inner_product` of the
    report)
  - add `partial_sum` algorithm (the section on `partial_sum` of the report)
  - add `adjacent_difference` algorithm (the section on `adjacent_difference`
    of the report)

## Version 11.1.0
(Sodium, March 2015)

- Use built-in predicates `valid` and `valid_read` instead of `valid_range`.
- Simplify loop invariants of `find_first_of`.
- Replace two loop invariants of `remove_copy` by ACSL lemmas.
- Rename several predicates
  - `IsEqual` → `EqualRanges`.
  - `IsMaximum` → `MaxElement`.
  - `IsMinimum` → `MinElement`.
  - `Reverse` → `Reversed`.
  - `IsSorted` → `Sorted`.
- Several changes for `Stack`:
  - Rename `Stack` functions from `foo_stack` to `stack_foo`.
  - Equality of stacks now ignores the `capacity` field. This is similar to how
    equality for objects of type `std::vector<T>` is defined. As a consequence
    `stack_full` is not well-defined any more. Other stack functions are not
    effected.
  - Remove all assertions from stack functions (including in axioms).
  - Describe predicate `Separated` in text.

## Version 10.1.1
(Neon, January 2015)

- use option `-wp-split` to create simpler (but more) proof obligations
- simplify definition of predicate `Count`
- add new predicates for lower and upper bounds of ranges and use it in
  - `max_element`
  - `min_element`
  - `lower_bound`
  - `upper_bound`
  - `equal_range`
  - `fill`
- use a new auxiliary assertion in `equal_range` to enable the complete
  *automatic* verification of this algorithm
- add predicate `Unchanged` and use it to simplify the specification of several
  algorithms
  - `swap_ranges`
  - `reverse`
  - `remove_copy`
  - `stack_push` and `stack_push_wd`
  - `stack_pop` and `stack_pop_wd`
- add predicate `Reverse` and use it for more concise specifications of
  - `reverse_copy`
  - `reverse`
- several changes in the two versions of `remove_copy`
  - use predicate `HasValue` instead of logic function `Count`
  - add predicate `PreserveCount`
  - reformulate logic function `RemoveCount`
  - add predicate `StableRemove`
  - add predicate `RemoveCountMonotonic`
  - add predicate `RemoveCountJump`
- use overloading in ACSL to create shorter logic names for `Stack`
- remove unnecessary labels in several `Stack` functions

## Version 10.1.0
(Neon, September 2014)

- remove additional labels in the `assumes` clauses of some stack function that
  were necessary due to an error in Oxygen
- provide a second version of `remove_copy` in order to explain the
  specification of the *stability* of the algorithms
- coarsen loop assigns of mutating algorithms
- temporarily remove the `unique_copy` algorithm

## Version 9.3.1
(Fluorine, not published)

- specify bounds of the return value of `count` and fix reads clause of `Count`
  predicate
- use an auxiliary function `make_pair` in the implementation of `equal_range`
- provide more precise loop assigns clauses for the mutating algorithms
  - simplify implementation of `fill`
  - removed the `ensures valid(p)` clause in specification of `swap`
  - simplify implementation of `swap_ranges`
  - simplify implementation of `copy`
  - fix implementation of `reverse_copy` after discovering an undefined
    behavior
  - new implementation of `reverse` that uses a simple `for`-loop
  - simplify implementation of `replace_copy`
  - refactor specification and simplify implementation of `remove_copy`
- remove work-around with `Pre`-label in `assumes` clauses of `stack_push` and
  `stack_pop`

## Version 9.3.0
(Fluorine, December 2013)

- adjustments for *Fluorine* release of Frama-C
- `swap` now ensures that its pointer arguments are valid after the function
  has been called
- change definition of `size_type` to `unsigned int`
- change implementation of the `iota` algorithm. The content of the field `a`
  is calculated by increasing the value `val` instead of sum `val+i`.
- change implementation of `fill`.
- The specification/ implementation of `Stack` has been revised by Kim
  Völlinger (*Einsatz des Beweisassistenten Coq zur deduktiven
  Programmverifikation*, Diplomarbeit, Humboldt-Universität zu Berlin, 2013)
  and now has a much better verification rate.

## Version 8.1.0
(Oxygen, not published)

- simplified specification and loop annotations of `replace_copy`
- add binary search variant `equal_range`
- greatly simplified specification of `remove_copy` by using the logic function
  `Count`
- remove chapter on heap operations

## Version 7.1.1
(Nitrogen, August 2012)

- improvements with respect to several suggestions and comments of Yannick Moy,
  e.g., specification refinements of `remove_copy`, `reverse_copy` and `iota`
- restricted verification of algorithms to Frama-C/WP with Alt-Ergo
- replaced deprecated `valid_range` by `valid`
- fixed inconsistencies in the description of the `Stack` data type
- binary search algorithms can now be proven without additional axioms for
  integer division
- changed axioms into lemmas to document that provability is expected, even if
  not currently granted
- adopted new Fraunhofer logo and contact email

## Version 7.1.0
(Nitrogen, December 2011)

- changed to Frama-C Nitrogen
- changed to Why 2.30
- discussed both plug-ins Frama-C/WP and Jessie
- removed `swap_values` algorithm

## Version 6.1.0
(Carbon, not published)

- changed definition of `Stack`
- renamed `reset_stack` to `init_stack`

## Version 5.1.1
(Boron, February 2011)

- prepared algorithms for checking by the new Frama-C/WP plug-in of Frama-C
- changed to Alt-Ergo Version 0.92, Z3 Version 2.11 and Why 2.27
- added List of user-defined predicates and logic functions
- added remarks on the relation of logical values in C and ACSL
- rewrote section on `equal` and `mismatch`
- used a simpler logical function to count elements in an array
- added `search` algorithm
- added chapter to unite the maximum/ minimum algorithms
- added chapter for the new `lower_bound`, `upper_bound` and `binary_search`
  algorithms
- added `swap_values` algorithm
- used `IsEqual` predicate for `swap_ranges` and `copy`
- added `reverse_copy` and `reverse` algorithms
- added `rotate_copy` algorithm
- added `unique_copy` algorithm
- added chapter on specification of the data type `Stack`

## Version 5.1.0
(Boron, May 2010)

- adaption to Frama-C Boron and Why 2.26 releases
- changed from the `-jessie-no-regions` command-line option to using the pragma
  `SeparationPolicy(value)`

## Version 4.2.2
(Beryllium, May 2010)

- changed to latest version of CVC3 2.2
- added additional remarks to our implementation of `find_first_of`
- changed `size_type` (`int`) to `integer` in all specifications
- removed casts in `fill` and `iota`
- renamed `is_valid_range` as `IsValidRange`
- renamed `has_value` as `HasValue`
- renamed predicate `all_equal` as `IsEqual`
- extended timeout to 30 sec.

## Version 4.2.1
(Beryllium, April 2010)

- added alternative specification of `remove_copy` algorithm that uses `ghost`
  variables
- added Chapter on heap operations
- added `mismatch` algorithm
- moved algorithms `adjacent_find` and `min_element` from the appendix to
  chapter on nonmutating algorithms
- added typedefs `size_type` and `value_type` and used them in all algorithms
- renamed `is_valid_int_range` as `is_valid_range`

## Version 4.2.0
(Beryllium, January 2010)

- complete rewrite of pre-release
- adaption to Frama-C Beryllium 2 release
