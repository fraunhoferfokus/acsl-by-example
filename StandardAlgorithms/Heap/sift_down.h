
#ifndef SIFT_DOWN_H_INCLUDED
#define SIFT_DOWN_H_INCLUDED

#include "Heap.acsl"
#include "MultisetReorder.acsl"

/*@
   requires   valid:    \valid(a + (0..n-1));
   requires   bounds:   0 <= root < n;
   requires   hfrom:    HeapFrom(a, root + 1, n);

   terminates           \true;
   exits                \false;
   assigns              a[0..n-1];

   ensures    hfrom:    HeapFrom(a, root, n);
   ensures    reorder:  MultisetReorder{Old,Here}(a, n);
*/
void sift_down(value_type* a, size_type n, size_type root);

#endif /* SIFT_DOWN_H_INCLUDED */

