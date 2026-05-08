
#include "pop_heap.h"
#include "heap_child.h"
#include "sift_down.h"
#include "MultisetUpdate.acsl"

void pop_heap(value_type* a, size_type n)
{
  if (1u < n) {
    if (a[n - 1u] < a[0u]) {

      value_type v = a[n - 1u];
      a[n - 1u] = a[0u];
      //@ ghost MidSwap: ;
      a[0u] = v;

      //@ assert update:      ArrayUpdate{MidSwap,Here}(a, n, 0, v);
      //@ assert update:      MultisetUpdate{MidSwap,Here}(a, n, 0, v);
      //@ assert reorder:     MultisetReorder{Pre,Here}(a, n);
      //@ assert max:         UpperBound(a, n, a[n-1]);
      //@ assert hfrom:       HeapFrom(a, 1, n-1);

      //@ ghost BeforeSift: ;
      sift_down(a, n - 1u, 0u);

      //@ assert unchanged:   Unchanged{BeforeSift,Here}(a, n-1, n);
      //@ assert reorder:     MultisetReorder{BeforeSift,Here}(a, n-1);
      //@ assert max:         UpperBound(a, n, a[n-1]);
    }
  }
}
