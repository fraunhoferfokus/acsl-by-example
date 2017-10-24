
#ifndef HEAP_SORT_H_INCLUDED
#define HEAP_SORT_H_INCLUDED

#include "MultisetUnchanged.h"
#include "Sorted.h"

/*@
   requires valid:  \valid(a + (0..n-1));

   assigns a[0..n-1];

   ensures sorted:   Sorted(a, n);
   ensures reorder:  MultisetUnchanged{Old, Here}(a, n);
*/
void heap_sort(value_type* a, size_type n);

#endif /* HEAP_SORT_H_INCLUDED */

