
#ifndef POP_HEAP_H_INCLUDED
#define POP_HEAP_H_INCLUDED

#include "Heap.acsl"
#include "MultisetUnchanged.acsl"

/*@
   requires bounds:     0 < n;
   requires valid:      \valid(a + (0..n-1));
   requires heap:       Heap(a, n);
   assigns              a[0..n-1];
   ensures heap:        Heap(a, n-1);
   ensures result:      a[n-1] == \old(a[0]);
   ensures max:         MaxElement(a, n, n-1);
   ensures reorder:     MultisetUnchanged{Old,Here}(a, n);
*/
void
pop_heap(value_type* a, size_type n);

#endif /* POP_HEAP_H_INCLUDED */

