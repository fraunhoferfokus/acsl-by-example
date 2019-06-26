
#ifndef SORTEDDOWNISHEAP_SPEC_INCLUDED
#define SORTEDDOWNISHEAP_SPEC_INCLUDED

#include "IsHeap.spec"

/*@
  predicate
    SortedDown{L}(value_type* a, integer n) =
      \forall integer i, j;
        0 <= i <= j < n ==> a[i] >= a[j];


  lemma
    SortedDownIsHeap{L}:
      \forall value_type *a, integer n;
        SortedDown(a, n) ==> IsHeap(a, n);
*/

#endif /* SORTEDDOWNISHEAP_SPEC_INCLUDED */

