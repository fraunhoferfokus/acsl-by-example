
#ifndef SORT_HEAP_H_INCLUDED
#define SORT_HEAP_H_INCLUDED

#include <limits.h>
#include "Heap.acsl"
#include "MultisetReorder.acsl"
#include "Increasing.acsl"

/*@
   requires valid:       \valid(a + (0..n-1));
   requires heap:        Heap(a, n);
   assigns               a[0..n-1];
   ensures reorder:      MultisetReorder{Old,Here}(a, n);
   ensures increasing:   Increasing(a, n);
*/
void
sort_heap(value_type* a, size_type n);

#endif /* SORT_HEAP_H_INCLUDED */

