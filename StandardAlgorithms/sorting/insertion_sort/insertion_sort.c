
#include "insertion_sort.h"
#include "upper_bound.h"
#include "rotate.h"
#include "ArrayBounds.spec"
#include "EqualRangesLemmas.spec"
#include "CircularShiftLemmas.spec"

void
insertion_sort(value_type* a, size_type n)
{
  /*@
    loop invariant bound:         0 <= i <= n;
    loop invariant reorder:       MultisetUnchanged{Pre,Here}(a, 0, i);
    loop invariant unchanged:     Unchanged{Pre,Here}(a, i, n);
    loop invariant increasing:    Increasing(a, i);
    loop assigns   i, a[0..n-1];
    loop variant   n - i;
  */
  for (size_type i = 0u; i < n; ++i) {
    const size_type k = upper_bound(a, i, a[i]);
    //@ assert bound:   0 <= k <= i;
    /*@
       requires increasing: UpperBound(a, k, a[i]);
       requires increasing: StrictLowerBound(a, k, i, a[i]);
       requires increasing: Increasing(a, k, i);
       assigns              a[k..i];
       ensures unchanged:   Unchanged{Old,Here}(a, 0, k);
       ensures unchanged:   Unchanged{Old,Here}(a, i+1, n);
       ensures reorder:     MultisetUnchanged{Old,Here}(a, 0, k);
       ensures reorder:     EqualRanges{Old,Here}(a, k, i, k+1);
       ensures reorder:     EqualRanges{Old,Here}(a, i, i+1, k);
       ensures increasing:  Increasing(a, 0, k);
       ensures increasing:  UpperBound(a, k, a[k]);
    */
    rotate(a + k, i - k, i - k + 1u);
    //@ assert increasing:  StrictLowerBound(a, k+1, i+1, a[k]);
    //@ assert increasing:  Increasing(a, k+1, i+1);
    //@ assert increasing:  Increasing(a, i+1);
    //@ assert reorder:     MultisetUnchanged{Pre,Here}(a, i+1);
  }
}

