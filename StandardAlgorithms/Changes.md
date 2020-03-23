
#Version 20.0.1

- add a third version for specifying linear search (find3)

- refactor definition of logic function Count

- adjacent_differenrcve_inv
	- reformulate AdjacentDifferenceInv to AdjacentDifferenceThenPartialSum
	- improve verification rate

- partial_sum_inv
	- reformulate PartialSumInv to PartialSumThenAdjacentDifference

- random_number
        - fixed disabling of 'unsigned overflow' warnings for bit operations

- unique_copy
        - adjusted makefiles to enable non-trivial test cases 
        - test cases for unique_copy are now also executed 

- RemovePartition
	- add logic function FindNotEqual
	- rename logic function RemoveSize to CountNotEqual
	- rename predicate ConstantRange to AllEqual
	- fix wrong definition of RemovePartitionInitial
	- use AllEqual in RemovePartitionInitial and Remove PartitionSegment
	- rename RemovePartitionNotValue to RemovePartitionNotEqual
