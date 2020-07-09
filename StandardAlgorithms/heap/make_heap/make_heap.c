
#include "make_heap.h"
#include "push_heap.h"
#include "Unchanged.acsl"

void
make_heap(value_type* a, size_type n)
{
  if (0u < n) {
    /*@
       loop invariant bounds:     1 <= i <= n;
       loop invariant heap:       Heap(a, i);
       loop invariant reorder:    MultisetUnchanged{Pre,Here}(a, n);
       loop invariant unchanged:  Unchanged{Pre,Here}(a, i+1, n);
       loop assigns   i, a[0..n-1];
       loop   variant n - i;
    */
    for (size_type i = 1u; i < n; ++i) {
      push_heap(a, i + 1u);
      //@ assert reorder:    MultisetUnchanged{LoopCurrent,Here}(a, i+1);
      //@ assert unchanged:  Unchanged{LoopCurrent,Here}(a, i+1, n);
      //@ assert reorder:    MultisetUnchanged{LoopCurrent,Here}(a, n);
    }

    //@ assert reorder:    MultisetUnchanged{Pre,Here}(a, n);
  }

  //@ assert  heap: Heap(a, n);
}

