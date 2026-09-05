
#ifndef HEAP_SIFT_DOWN_H_INCLUDED
#define HEAP_SIFT_DOWN_H_INCLUDED

#include "HeapForest.acsl"
#include "MultisetReorder.acsl"

/*@
   requires   valid:    \valid(a + (0..n-1));
   requires   bounds:   0 <= root < n;
   requires   forest:   HeapForest(a, root + 1, n);

   terminates           \true;
   exits                \false;
   assigns              a[0..n-1];

   ensures    forest:   HeapForest(a, root, n);
   ensures    reorder:  MultisetReorder{Old,Here}(a, n);
*/
void heap_sift_down(value_type* a, size_type n, size_type root);

#endif /* HEAP_SIFT_DOWN_H_INCLUDED */
