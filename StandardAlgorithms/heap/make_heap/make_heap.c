
#include "make_heap.h"
#include "../push_heap/push_heap.h"
#include "Unchanged.h"

void make_heap(value_type* a, size_type n)
{
  if (0u < n) {

    /*@
       loop invariant bounds:     2 <= i <= n+1;
       loop invariant heap:       IsHeap(a, i-1);
       loop invariant reorder:    MultisetUnchanged{Pre,Here}(a, i);
       loop invariant unchanged:  Unchanged{Pre,Here}(a, i, n);
       loop assigns   i, a[0..n-1];
       loop   variant n - i;
    */
    for (size_type i = 2; i <= n; i++) {
      push_heap(a, i);
    }
  }

  //@ assert  heap: IsHeap(a, n);
}

