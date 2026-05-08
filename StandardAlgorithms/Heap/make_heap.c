
#include "make_heap.h"
#include "heap_child.h"
#include "heap_parent.h"
#include "push_heap.h"
#include "sift_down.h"
#include "MultisetUpdate.acsl"
#include "Unchanged.acsl"

void make_heap(value_type* a, size_type n)
{
  if (1u < n) {
    size_type root = heap_parent(n - 1u) + 1u;

    /*@
       loop invariant bounds:     0 <= root <= HeapParent(n - 1u) + 1;
       loop invariant hfrom:      HeapFrom(a, root, n);
       loop invariant reorder:    MultisetReorder{Pre,Here}(a, n);
       loop assigns               root, a[0..n-1];
       loop variant               root;
    */
    while (0u < root) {
      --root;
      //@ assert hfrom_next:     HeapFrom(a, root + 1u, n);
      sift_down(a, n, root);
      //@ assert hfrom:          HeapFrom(a, root, n);
      //@ assert reorder_step:   MultisetReorder{LoopCurrent,Here}(a, n);
      //@ assert reorder:        MultisetReorder{Pre,Here}(a, n);
    }
    //@ assert hfrom_zero:       HeapFrom(a, 0, n);
  }

  //@ assert heap:               Heap(a, n);
}

