
#ifndef PUSH_HEAP_H_INCLUDED
#define PUSH_HEAP_H_INCLUDED

#include "IsHeap.h"
#include "MultisetUnchanged.h"

/*@
   requires nonempty: n > 0;
   requires valid:    \valid(a + (0..n-1));
   requires heap:     IsHeap(a, n-1);

   assigns a[0..n-1];

   ensures heap:      IsHeap(a, n);
   ensures reorder:   MultisetUnchanged{Old,Here}(a, n);
*/
void push_heap(value_type* a, size_type n);

#endif /* PUSH_HEAP_H_INCLUDED */

