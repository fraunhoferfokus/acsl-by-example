
#ifndef ISHEAP_PREDICATE_INCLUDED
#define ISHEAP_PREDICATE_INCLUDED

#include "HeapLogic.h"

/*@
  predicate
    IsHeap{L}(value_type* a, integer n) = 
      \forall integer i; 0 < i < n  ==> a[i] <= a[HeapParent(i)];
*/

#endif /* ISHEAP_PREDICATE_INCLUDED */

