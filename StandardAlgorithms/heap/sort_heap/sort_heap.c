
#include "sort_heap.h"
#include "pop_heap.h"
#include "IncreasingLemmas.acsl"

void
sort_heap(value_type* a, size_type n)
{
  /*@
     loop invariant bound:        0 <= i <= n;
     loop invariant heap:         Heap(a, i);
     loop invariant lower:        LowerBound(a, i, n, a[0]);
     loop invariant reorder:      MultisetUnchanged{Pre,Here}(a, 0, n);
     loop invariant increasing:   WeaklyIncreasing(a, i, n);
     loop assigns i, a[0..n-1];
     loop variant i;
  */
  for (size_type i = n; i > 1u; --i) {
    /*@
        requires heap:     Heap(a, i);
        assigns  a[0..i-1];
        ensures  heap:     Heap(a, i-1);
        ensures  max:      a[i-1] == \old(a[0]);
        ensures  max:      MaxElement(a, i, i-1);
        ensures  reorder:  MultisetUnchanged{Old,Here}(a, 0, i);
        ensures  reorder:  Unchanged{Old,Here}(a, i, n);
    */
    pop_heap(a, i);
    //@ assert lower:  LowerBound(a, i, n, a[i-1]);
  }

  //@ assert increasing: Increasing(a, n);
}

