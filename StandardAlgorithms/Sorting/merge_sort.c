
#include "merge_sort.h"
#include "merge.h"
#include "copy.h"
#include "IncreasingLemmas.acsl"
#include "MultisetUnionToReorder.acsl"
#include "UnchangedLemmas.acsl"

void merge_sort(value_type* a, size_type n, value_type* b)
{
  if (n < 2u) {
    return;
  }

  const size_type m = n / 2u;
  //@ assert bound:       0 < m < n;

  merge_sort(a, m, b);
  //@ ghost Half: ;
  //@ assert increasing:  Increasing(a, 0, m);
  //@ assert reorder:     MultisetReorder{Pre,Here}(a, 0, m);
  //@ assert unchanged:   Unchanged{Pre,Here}(a, m, n);
  //@ assert reorder:     MultisetReorder{Pre,Here}(a, m, n);

  merge_sort(a + m, n - m, b + m);
  //@ ghost Sorted: ;
  //@ assert increasing:  Increasing(a + m, 0, n-m);
  //@ assert increasing:  Increasing(a, m, n);
  //@ assert unchanged:   Unchanged{Half,Here}(a, 0, m);
  //@ assert increasing:  Increasing(a, 0, m);
  //@ assert reorder:     MultisetReorder{Half,Here}(a + m, 0, n-m);
  //@ assert reorder:     MultisetReorder{Half,Here}(a, m, n);
  //@ assert reorder:     MultisetReorder{Pre,Here}(a, m, n);
  //@ assert reorder:     MultisetReorder{Half,Here}(a, 0, m);
  //@ assert reorder:     MultisetReorder{Pre,Here}(a, 0, m);
  //@ assert reorder:     MultisetReorder{Pre,Here}(a, 0, n);

  merge(a, m, a + m, n - m, b);
  //@ ghost Merged: ;
  //@ assert increasing:  Increasing(b, 0, n);
  //@ assert multiset:    MultisetUnion(a, m, a + m, n-m, b);
  //@ assert unchanged:   Unchanged{Sorted,Here}(a, 0, m);
  //@ assert unchanged:   Unchanged{Sorted,Here}(a, m, n);
  //@ assert unchanged:   Unchanged{Sorted,Here}(a, 0, n);
  //@ assert reorder:     MultisetReorder{Sorted,Here}(a, 0, n);
  //@ assert reorder:     MultisetReorder{Pre,Here}(a, 0, n);

  copy(b, n, a);
  //@ assert equal:       Equal{Merged,Here}(b, n, a);
  //@ assert increasing:  Increasing(a, 0, n);
  //@ assert reorder:     MultisetReorder{Merged,Here}(a, 0, n);
  //@ assert reorder:     MultisetReorder{Pre,Merged}(a, 0, n);
  //@ assert reorder:     MultisetReorder{Pre,Here}(a, 0, n);
}

