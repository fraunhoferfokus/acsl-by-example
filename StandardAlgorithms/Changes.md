
#Version 20.0.0

- remove why3 and alt-ergo lemmas from driver

- switch from memory model 'Typed+Ref' to 'Typed'

- add new example bubble_sort

- rewrite random_shuffle to shuffle
	- change signature of random_number 
	- add random_init

- improve specification and verification rate of numeric algorithms
	- resolve overloaded version of Accumulate into AccumulateDefault
	- resolve overloaded version of AccumulateBounds into AccumulateDefaultBounds
	- improve definition of predicate PartialSum
	- add lemmas Difference0 and DifferenceNext
	- add predicate DefaultBounds

- rename Sorted -> Increasing
	- remove SortedDownIsHeap
	- rename EqualRangesPreservesSorted -> EqualRangesPreservesIncreasing
	- rename SortedUpperBound -> IncreasingUpperBound
	- rename WeaklySortedAddElement -> WeaklyIncreasingAddElement
	- rename WeaklySortedShift -> WeaklyIncreasingShift
	- rename EqualRangesWeaklySorted -> EqualRangesWeaklyIncreasing
	- rename WeaklySortedJoin -> WeaklyIncreasingJoin
	- rename WeaklySortedLemmas -> WeaklyIncreasingLemmas
	- rename SortedIFFWeaklySorted -> IncreasingIFFWeaklyIncreasing
	- rename SortedImpliesWeaklySorted -> IncreasingImpliesWeaklyIncreasing
	- rename WeaklySortedImpliesSorted -> WeaklyIncreasingImpliesIncreasing
	- rename WeaklySorted -> WeaklyIncreasing
	- rename SortedShift -> IncreasingShift

- add assigns in behaviors of maxmin and nonmutating algorithms
        - search
        - find
        - find_end
        - adjacent_find
        - find2
        - mismatch
        - find_first_of
        - max_element
        - max_element2
        - min_element
        - minmax_element

- replace, where applicable, ghost labels by loop labels or statement labels

- remove lemma SwapImpliesMultisetUnchanged by using predicate Swapped

