
#include "make_heap.h"
#include "../push_heap/push_heap.h"
#include "Unchanged.h"

void make_heap(value_type* a, size_type n)
{
  if (0u < n) {

    /*@
       loop invariant bounds:     1 <= i <= n;
       loop invariant heap:       IsHeap(a, i);
       loop invariant reorder:    MultisetUnchanged{Pre,Here}(a, i+1);
       loop invariant unchanged:  Unchanged{Pre,Here}(a, i+1, n);
       loop assigns   i, a[0..n-1];
       loop   variant n - i;
    */
    for (size_type i = 1; i < n; ++i) {
      push_heap(a, i+1u);
    }
  }

  //@ assert  heap: IsHeap(a, n);
}

