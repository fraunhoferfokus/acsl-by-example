
#include "pop_heap.h"
#include "swap.h"
#include "heap_sift_down.h"
#include "MultisetSwap.acsl"
#include "MultisetReorderLemmas.acsl"

void pop_heap(value_type* a, size_type n)
{
  if (1u < n) {
    //@ assert max:  MaxElement(a, n, 0);
    if (a[n - 1u] < a[0u]) { // otherwise a[0] == a[n-1] and nothing to be done
      //@ ghost Before: ;
      swap(a, a + n - 1u);
      //@ assert swapped:   ArraySwap{Before,Here}(a, 0, n-1, n);
      //@ assert reorder:   MultisetReorder{Pre,Here}(a, n);
      //@ assert max:       UpperBound(a, n-1, a[n-1]);
      //@ assert forest:    HeapForest(a, 1, n-1);

      //@ ghost BeforeSift: ;
      heap_sift_down(a, n - 1u, 0u);

      //@ assert unchanged: Unchanged{BeforeSift,Here}(a, n-1, n);
      //@ assert reorder:   MultisetReorder{Pre,Here}(a, n);
      //@ assert heap:      Heap(a, n-1);
      //@ assert max:       SomeEqual{BeforeSift}(a, n-1, a[0]);
      //@ assert max:       a[0] <= a[n-1];
      //@ assert max:       UpperBound(a, n, a[n-1]);
    }
  }
}
