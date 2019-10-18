
#include "partial_sort.h"

#include "make_heap.h"
#include "pop_heap.h"
#include "push_heap.h"
#include "sort_heap.h"
#include "swap.h"

#include "LowerBound.spec"
#include "MultisetUnchangedLemmas.spec"
#include "HeapMaximum.spec"
#include "ReorderPreservesLowerBound.spec"
#include "ReorderPreservesUpperBound.spec"
#include "PartialReorderPreservesLowerBounds.spec"
#include "SwappedInsideMultisetUnchanged.spec"
#include "SwappedInsidePreservesMultisetUnchanged.spec"

void
partial_sort(value_type* a, size_type m, size_type n)
{
  if (m > 0u) {
    make_heap(a, m);

    //@ assert reorder: Unchanged{Pre,Here}(a, m, n);
    /*@
      loop invariant bound:     m <= i <= n;
      loop invariant heap:      IsHeap(a, m);
      loop invariant upper:     UpperBound(a, 0, m, a[0]);
      loop invariant lower:     LowerBound(a, m, i, a[0]);
      loop invariant reorder:   MultisetUnchanged{Pre,Here}(a, i);
      loop invariant unchanged: Unchanged{Pre,Here}(a, i, n);
      loop assigns              i, a[0..n-1];
      loop variant              n-i;
    */
    for (size_type i = m; i < n; ++i)
      if (a[i] < a[0u]) {
        /*@
          assigns              a[0..m-1];
          ensures heap:        IsHeap(a, m-1);
          ensures max:         a[m-1] == \old(a[0]);
          ensures max:         MaxElement(a, m, m-1);
          ensures reorder:     MultisetUnchanged{Old, Here}(a, m);
          ensures unchanged:   Unchanged{Old, Here}(a, m, i);
          ensures unchanged:   Unchanged{Old, Here}(a, m, n);
        */
        pop_heap(a, m);
        //@ assert lower:      a[0] <= a[m-1];
        //@ assert lower:      a[i] <  a[m-1];
        //@ assert lower:      LowerBound(a, m, i, a[m-1]);
        //@ assert upper:      UpperBound(a, 0, m-1, a[0]);
        //@ assert upper:      UpperBound(a, 0, m,   a[m-1]);
        //@ assert partition:  Partition(a, m, i);
        //@ assert reorder:    MultisetUnchanged{Pre,Here}(a, i);

        //@ ghost BeforeSwap:
        swap(a + m - 1u, a + i);
        //@ assert swapped:    SwappedInside{BeforeSwap,Here}(a, m-1, i, n);
        //@ assert reorder:    MultisetUnchanged{BeforeSwap,Here}(a, i+1);
        //@ assert reorder:    MultisetUnchanged{Pre,Here}(a, i+1);
        //@ assert unchanged:  Unchanged{Pre,Here}(a, i+1, n);
        //@ assert lower:      a[m-1] < a[i];
        //@ assert lower:      \forall integer k; 0 <= k < m ==> LowerBound(a, m, i+1, a[k]);
        //@ assert upper:      UpperBound(a, 0, m-1, a[0]);

        /*@
          assigns              a[0..m-1];
          ensures heap:        IsHeap(a, m);
          ensures reorder:     MultisetUnchanged{Old,Here}(a, m);
          ensures unchanged:   Unchanged{Old,Here}(a, m, i+1);
          ensures unchanged:   Unchanged{Old,Here}(a, i+1, n);
        */
        push_heap(a, m);
        //@ assert upper:      UpperBound(a, 0, m,   a[0]);
        //@ assert lower:      LowerBound(a, m, i+1, a[0]);
      }

    //@ assert partition: Partition(a, m, n);
    /*@
      assigns             a[0..m-1];
      ensures sorted:     Sorted(a, m);
      ensures reorder:    MultisetUnchanged{Old,Here}(a, m);
      ensures reorder:    MultisetUnchanged{Old,Here}(a, m, n);
    */
    sort_heap(a, m);
    //@ assert reorder:   MultisetUnchanged{Pre,Here}(a, n);
    //@ assert partition: Partition(a, m, n);
  }
}

