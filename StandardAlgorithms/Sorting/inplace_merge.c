
#include "inplace_merge.h"
#include "rotate.h"
#include "ArrayBounds.acsl"
#include "IncreasingLemmas.acsl"
#include "Partition.acsl"
#include "RotateLemmas.acsl"
#include "WeaklyIncreasingLemmas.acsl"

void inplace_merge(value_type* a, size_type m, size_type n)
{
  size_type i = 0u;
  size_type j = m;

  /*@
    loop invariant bound:         0 <= i <= j <= n;
    loop invariant bound:         m <= j;
    loop invariant increasing:    WeaklyIncreasing(a, j);
    loop invariant increasing:    WeaklyIncreasing(a, j, n);
    loop invariant partition:     Partition(a, 0, i, n);
    loop invariant unchanged:     Unchanged{Pre,Here}(a, j, n);
    loop invariant reorder:       MultisetReorder{Pre,Here}(a, n);
    loop assigns   i, j, a[0..n-1];
    loop variant   n - i;
  */
  while (i < j && j < n) {
    if (a[i] <= a[j]) {
      i++;
    }
    else {
      //@ ghost Before: ;
      //@ assert lower:       StrictLowerBound(a, i, j, a[j]);
      //@ assert lower:       LowerBound(a, j, n, a[j]);
      rotate(a + i, j - i, j + 1u - i);
      //@ assert equal:       a[i] == \at(a[j],Before);
      //@ assert unchanged:   Unchanged{Before,Here}(a, 0, i);
      //@ assert unchanged:   Unchanged{Before,Here}(a, j+1, n);
      //@ assert lower:       StrictLowerBound(a, i+1, j+1, a[i]);
      //@ assert increasing:  WeaklyIncreasing(a, i+1, j+1);
      i++;
      j++;
    }
  }
}
