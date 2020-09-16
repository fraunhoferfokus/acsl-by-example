
#ifndef INSERTION_SORT_H_INCLUDED
#define INSERTION_SORT_H_INCLUDED

#include "MultisetReorder.acsl"
#include "Increasing.acsl"

/*@
   requires valid:       \valid(a + (0..n-1));
   assigns               a[0..n-1];
   ensures reorder:      MultisetReorder{Old,Here}(a, n);
   ensures increasing:   Increasing(a, n);
*/
void
insertion_sort(value_type* a, size_type n);

#endif /* INSERTION_SORT_H_INCLUDED */

