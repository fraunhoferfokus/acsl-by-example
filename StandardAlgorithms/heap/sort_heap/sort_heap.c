
#include "sort_heap.h"
#include "pop_heap.h"
#include "LowerBound.spec"
#include "SortedUpperBound.spec"
#include "Unchanged.spec"
#include "MultisetUnchangedLemmas.spec"

void
sort_heap(value_type* a, size_type n)
{
  /*@
     loop invariant bound:    0 <= i <= n;
     loop invariant heap:     IsHeap(a, i);
     loop invariant sorted:   Sorted(a, i, n);
     loop invariant lower:    LowerBound(a, i, n, a[0]);
     loop invariant reorder:  MultisetUnchanged{Pre,Here}(a, 0, n);
     loop assigns i, a[0..n-1];
     loop variant i;
  */
  for (size_type i = n; i > 1u; --i) {
    /*@
        requires heap:     IsHeap(a, i);
        assigns  a[0..i-1];
        ensures  heap:     IsHeap(a, i-1);
        ensures  max:      a[i-1] == \old(a[0]);
        ensures  max:      MaxElement(a, i, i-1);
        ensures  reorder:  MultisetUnchanged{Old,Here}(a, 0, i);
        ensures  reorder:  Unchanged{Old,Here}(a, i, n);
    */
    pop_heap(a, i);
    //@ assert lower:  LowerBound(a, i, n, a[i-1]);
  }
}

