
#ifndef PUSH_HEAP_H_INCLUDED
#define PUSH_HEAP_H_INCLUDED

#include "IsHeap.h"
#include "Reorder.h"

/*@
   requires positive: n > 0;
   requires valid:    \valid_read(a + (0..n-1));
   requires heap:     IsHeap(a, n-1);

   assigns a[0..n-1];

   ensures heap:      IsHeap(a, n);
   ensures max:       MaxElement(a, n, 0);
   ensures reorder:   Reorder{Old, Here}(a, n);
*/
void push_heap(value_type* a, size_type n);

#endif /* PUSH_HEAP_H_INCLUDED */

