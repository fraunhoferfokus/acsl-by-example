
#ifndef MAKE_HEAP_H_INCLUDED
#define MAKE_HEAP_H_INCLUDED

#include "Heap.acsl"
#include "MultisetReorder.acsl"

/*@
   requires valid:  \valid(a + (0..n-1));
   assigns          a[0..n-1];
   ensures heap:    Heap(a, n);
   ensures reorder: MultisetReorder{Old,Here}(a, n);
*/
void
make_heap(value_type* a, size_type n);

#endif /* MAKE_HEAP_H_INCLUDED */

