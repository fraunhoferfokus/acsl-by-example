
#ifndef POP_HEAP_H_INCLUDED
#define POP_HEAP_H_INCLUDED

#include "IsHeap.h"
#include "MaxElement.h"
#include "MultisetUnchanged.h"
#include <limits.h>

/*@
   requires limits: 1 <= n <  (UINT_MAX-2)/2;
   requires valid:  \valid(a + (0..n-1));
   requires heap:   IsHeap(a, n);

   assigns a[0..n-1];

   ensures heap:    IsHeap(a, n-1);
   ensures result:  a[n-1] == \old(a[0]);
   ensures max:     MaxElement(a, n, n-1);
   ensures reorder: MultisetUnchanged{Old, Here}(a, n);
*/
void pop_heap(value_type* a, size_type n);

#endif /* POP_HEAP_H_INCLUDED */

