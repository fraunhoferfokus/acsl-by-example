
#ifndef MAKE_HEAP_H_INCLUDED
#define MAKE_HEAP_H_INCLUDED

#include <limits.h>
#include "IsHeap.h"
#include "HeapMaximum.h"
#include "MultisetUnchanged.h"

/*@
   requires limit:  n < UINT_MAX;
   requires valid:  \valid(a + (0..n-1));

   assigns a[0..n-1];

   ensures heap:    IsHeap(a, n);
   ensures max:     n > 0 ==> MaxElement(a, n, 0);
   ensures reorder: MultisetUnchanged{Old,Here}(a, n);
*/
void make_heap(value_type* a, size_type n);

#endif /* MAKE_HEAP_H_INCLUDED */

