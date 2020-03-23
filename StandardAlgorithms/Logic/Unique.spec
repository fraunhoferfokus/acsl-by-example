
#ifndef UNIQUE_SPEC_INCLUDED
#define UNIQUE_SPEC_INCLUDED

#include "UniquePartition.spec"
#include "HasEqualNeighbors.spec"

/*@
  axiomatic Unique
  {
    predicate
    Unique(value_type* a, integer n, value_type* b) =
      \forall integer k; 0 <= k < UniqueSize(a, n)  ==>
        b[k] == a[UniquePartition(a, n, k)];

    lemma UniqueImpliesNoEqualNeighbors:
      \forall value_type *a, *b, integer n;
         Unique(a, n, b)  ==>  !HasEqualNeighbors(b, UniqueSize(a, n));

    lemma UniquePreserve{K,L}:
      \forall value_type *a, *b, integer i, k, n;
        0 <= k <= i < n           ==>
        k == UniqueSize{L}(a, i)  ==>
        Unique{K}(a, i, b)        ==>
        Unchanged{K,L}(b, k)      ==>
        Unchanged{K,L}(a, n)      ==>
        Unique{L}(a, i, b);
  }
*/

#endif /* UNIQUE_SPEC_INCLUDED */

