
#ifndef SORTEDDOWNISHEAP_H_INCLUDED
#define SORTEDDOWNISHEAP_H_INCLUDED

#include "IsHeap.h"

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

#endif /* SORTEDDOWNISHEAP_H_INCLUDED */

