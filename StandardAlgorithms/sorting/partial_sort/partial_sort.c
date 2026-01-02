
#include "partial_sort.h"

#include "make_heap.h"
#include "pop_heap.h"
#include "push_heap.h"
#include "sort_heap.h"
#include "swap.h"

#include "PartitionLemmas.acsl"
#include "MultisetSwap.acsl"

void
partial_sort(value_type* a, size_type m, size_type n)
{
  if (m > 0u) {
    make_heap(a, m);

    //@ assert reorder: Unchanged{Pre,Here}(a, m, n);
    /*@
      loop invariant bound:     m <= i <= n;
      loop invariant heap:      Heap(a, m);
      loop invariant upper:     UpperBound(a, 0, m, a[0]);
      loop invariant lower:     LowerBound(a, m, i, a[0]);
      loop invariant reorder:   MultisetReorder{Pre,Here}(a, i);
      loop invariant unchanged: Unchanged{Pre,Here}(a, i, n);
      loop assigns              i, a[0..n-1];
      loop variant              n-i;
    */
    for (size_type i = m; i < n; ++i) {
      if (a[i] < a[0u]) {
        //@ ghost BeforePop: ;
        pop_heap(a, m);
        //@ assert lower:      a[0] <= a[m-1];
        //@ assert lower:      a[i] <  a[m-1];
        //@ assert lower:      LowerBound(a, m, i, a[m-1]);
        //@ assert upper:      UpperBound(a, 0, m-1, a[0]);
        //@ assert upper:      UpperBound(a, 0, m,   a[m-1]);
        //@ assert partition:  Partition(a, m, i);
        //@ assert unchanged:  Unchanged{BeforePop,Here}(a, m, i);
        //@ assert reorder:    MultisetReorder{BeforePop,Here}(a, m);
        //@ assert reorder:    MultisetReorder{Pre,Here}(a, i);
        //@ assert unchanged:  Unchanged{Pre,Here}(a, i, n);

        //@ ghost BeforeSwap: ;
        //@ assert reorder:    MultisetReorder{Pre,Here}(a, i+1);
        swap(a + m - 1u, a + i);
        //@ assert swapped:    ArraySwap{BeforeSwap,Here}(a, m-1, i, n);
        //@ assert unchanged:  Unchanged{BeforeSwap,Here}(a, m-1);
        //@ assert unchanged:  Unchanged{Pre,Here}(a, i+1, n);
        //@ assert reorder:    MultisetReorder{BeforeSwap,Here}(a, m-1, i+1);
        //@ assert reorder:    MultisetReorder{BeforeSwap,Here}(a, i+1);
        //@ assert reorder:    MultisetReorder{Pre,Here}(a, i+1);
        //@ assert lower:      a[m-1] < a[i];
        //@ assert partition:  Partition(a, m, i+1);
        //@ assert upper:      UpperBound(a, 0, m-1, a[0]);

        //@ ghost BeforePush: ;
        push_heap(a, m);
        //@ assert heap:       Heap(a, m);
        //@ assert unchanged:  Unchanged{BeforePush,Here}(a, m, i+1);
        //@ assert unchanged:  Unchanged{BeforePush,Here}(a, i+1, n);
        //@ assert reorder:    MultisetReorder{Pre,Here}(a, i+1);
        //@ assert upper:      UpperBound(a, 0, m,   a[0]);
        //@ assert lower:      LowerBound(a, m, i+1, a[0]);
      }
    }

    //@ assert partition: Partition(a, m, n);
    //@ ghost BeforeSort: ;
    sort_heap(a, m);
    //@ assert unchanged:  Unchanged{BeforeSort,Here}(a, m, n);
    //@ assert reorder:    MultisetReorder{BeforeSort,Here}(a, m);
    //@ assert reorder:    MultisetReorder{Pre,Here}(a, n);
    //@ assert partition:  Partition(a, m, n);
  }
}

