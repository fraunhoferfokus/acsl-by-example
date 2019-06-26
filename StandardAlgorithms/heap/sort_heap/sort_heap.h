
#ifndef SORT_HEAP_H_INCLUDED
#define SORT_HEAP_H_INCLUDED

#include <limits.h>
#include "IsHeap.spec"
#include "MultisetUnchanged.spec"
#include "Sorted.spec"

/*@
   requires valid:  \valid(a + (0..n-1));
   requires heap:   IsHeap(a, n);

   assigns a[0..n-1];

   ensures sorted:   Sorted(a, n);
   ensures reorder:  MultisetUnchanged{Old, Here}(a, n);
*/
void
sort_heap(value_type* a, size_type n);

#endif /* SORT_HEAP_H_INCLUDED */

