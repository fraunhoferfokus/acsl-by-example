
#include "make_heap.h"
#include "heap_parent.h"
#include "heap_sift_down.h"

void make_heap(value_type* a, size_type n)
{
  if (1u < n) {
    size_type root = heap_parent(n - 1u) + 1u;

    /*@
       loop invariant bounds:     0 <= root <= HeapParent(n - 1u) + 1;
       loop invariant forest:     HeapForest(a, root, n);
       loop invariant reorder:    MultisetReorder{Pre,Here}(a, n);
       loop assigns               root, a[0..n-1];
       loop variant               root;
    */
    while (0u < root) {
      --root;
      //@ assert forest_next:  HeapForest(a, root + 1u, n);
      heap_sift_down(a, n, root);
      //@ assert forest:       HeapForest(a, root, n);
      //@ assert reorder_step: MultisetReorder{LoopCurrent,Here}(a, n);
      //@ assert reorder:      MultisetReorder{Pre,Here}(a, n);
    }

    //@ assert forest_zero:    HeapForest(a, 0, n);
  }

  //@ assert heap:             Heap(a, n);
}
