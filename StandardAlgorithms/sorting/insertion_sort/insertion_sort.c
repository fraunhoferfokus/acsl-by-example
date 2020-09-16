
#include "insertion_sort.h"
#include "upper_bound.h"
#include "rotate.h"
#include "ArrayBounds.acsl"
#include "CircularShiftLemmas.acsl"
#include "IncreasingLemmas.acsl"

void
insertion_sort(value_type* a, size_type n)
{
  /*@
    loop invariant bound:         0 <= i <= n;
    loop invariant reorder:       MultisetReorder{Pre,Here}(a, 0, i);
    loop invariant unchanged:     Unchanged{Pre,Here}(a, i, n);
    loop invariant increasing:    WeaklyIncreasing(a, i);
    loop assigns   i, a[0..n-1];
    loop variant   n - i;
  */
  for (size_type i = 0u; i < n; ++i) {
    const size_type k = upper_bound(a, i, a[i]);
    //@ assert bound:   0 <= k <= i;
    /*@
       requires increasing: UpperBound(a, k, a[i]);
       requires increasing: StrictLowerBound(a, k, i, a[i]);
       requires increasing: WeaklyIncreasing(a, k, i);
       assigns              a[k..i];
       ensures unchanged:   Unchanged{Old,Here}(a, 0, k);
       ensures unchanged:   Unchanged{Old,Here}(a, i+1, n);
       ensures reorder:     Equal{Old,Here}(a, k, i, k+1);
       ensures reorder:     Equal{Old,Here}(a, i, i+1, k);
       ensures increasing:  WeaklyIncreasing(a, 0, k);
    */
    //@ assert increasing:  UpperBound(a, k, a[i]);
    rotate(a + k, i - k, i - k + 1u);
    //@ assert increasing:  UpperBound(a, k, a[k]);
    //@ assert increasing:  StrictLowerBound(a, k+1, i+1, a[k]);
    //@ assert increasing:  WeaklyIncreasing(a, k+1, i+1);
    //@ assert increasing:  WeaklyIncreasing(a, i+1);
    //@ assert reorder:     MultisetReorder{LoopCurrent,Here}(a, 0, k);
    //@ assert reorder:     MultisetReorder{LoopCurrent,Here}(a, k, i+1);
    //@ assert reorder:     MultisetReorder{LoopCurrent,Here}(a, 0, i+1);
    //@ assert reorder:     MultisetReorder{Pre,Here}(a, i+1);
  }

  //@ assert increasing: Increasing(a, n);
}

