
#include "sort_heap.h"
#include "pop_heap.h"
#include "IncreasingLemmas.acsl"

void
sort_heap(value_type* a, size_type n)
{
  /*@
     loop invariant bound:       0 <= i <= n;
     loop invariant heap:        Heap(a, i);
     loop invariant lower:       LowerBound(a, i, n, a[0]);
     loop invariant reorder:     MultisetReorder{Pre,Here}(a, 0, n);
     loop invariant increasing:  WeaklyIncreasing(a, i, n);
     loop assigns i, a[0..n-1];
     loop variant i;
  */
  for (size_type i = n; i > 1u; --i) {
    //@ ghost Before: ;
    pop_heap(a, i);
    //@ assert lower:    LowerBound(a, i, n, a[i-1]);
    //@ assert reorder:  MultisetReorder{Before,Here}(a, 0, i);
    //@ assert reorder:  Unchanged{Before,Here}(a, i, n);
  }

  //@ assert increasing: Increasing(a, n);
}

