
#ifndef HEAPMAXIMUMCHILD_SPEC_INCLUDED
#define HEAPMAXIMUMCHILD_SPEC_INCLUDED

#include "Heap.spec"
#include "limits.h"

/*@
  predicate
    HeapMaximumChild{L}(value_type* a, integer n,
                        integer p,     integer c) =
      0 <= p < n-1                                            &&
      (p < (SIZE_TYPE_MAX-1)/2  ==>  p == HeapParent(c))      &&
      (HeapLeft(p)  < n-1       ==>  a[HeapLeft(p)]  <= a[c]) &&
      (HeapRight(p) < n-1       ==>  a[HeapRight(p)] <= a[c]);
*/

#endif /* HEAPMAXIMUMCHILD_SPEC_INCLUDED */

