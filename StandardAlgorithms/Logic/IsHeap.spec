
#ifndef ISHEAP_SPEC_INCLUDED
#define ISHEAP_SPEC_INCLUDED

#include "Heap.spec"

/*@
  predicate
    IsHeap{L}(value_type* a, integer n) =
      \forall integer i; 0 < i < n  ==> a[i] <= a[HeapParent(i)];
*/

#endif /* ISHEAP_SPEC_INCLUDED */

