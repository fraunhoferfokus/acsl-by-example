
#ifndef SELECTION_SORT_H_INCLUDED
#define SELECTION_SORT_H_INCLUDED

#include "MultisetUnchanged.acsl"
#include "Increasing.acsl"

/*@
   requires valid:       \valid(a + (0..n-1));
   assigns               a[0..n-1];
   ensures reorder:      MultisetUnchanged{Old,Here}(a, n);
   ensures increasing:   Increasing(a, n);
*/
void
selection_sort(value_type* a, size_type n);

#endif /* SELECTION_SORT_H_INCLUDED */

