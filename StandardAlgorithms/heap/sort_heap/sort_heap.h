
#ifndef SORT_HEAP_H_INCLUDED
#define SORT_HEAP_H_INCLUDED

#include "IsHeap.h"
#include "MultisetUnchanged.h"
#include "Sorted.h"
#include <limits.h>

/*@
   requires limit:  0 < n < (INT_MAX-2)/2;
   requires valid:  \valid(a + (0..n-1));
   requires heap:   IsHeap(a, n);

   assigns a[0..n-1];

   ensures sorted:   Sorted(a, n);
   ensures reorder:  MultisetUnchanged{Old, Here}(a, n);
*/
void sort_heap(value_type* a, size_type n);

#endif /* SORT_HEAP_H_INCLUDED */

