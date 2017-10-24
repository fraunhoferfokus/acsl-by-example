
#include "insertion_sort.h"
#include "../../binarysearch/upper_bound/upper_bound.h"
#include "../../mutating/rotate/rotate.h"
#include "LowerBound.h"
#include "MultisetUnchangedLemmas.h"
#include "EqualRangesPreservesSorted.h"
#include "RotatePreservesStrictLowerBound.h"
#include "RotateImpliesMultisetUnchanged.h"

void insertion_sort(value_type* a, size_type n)
{
  /*@
    loop invariant bound:     0 <= i <= n;
    loop invariant sorted:    Sorted(a, i);
    loop invariant reorder:   MultisetUnchanged{Pre,Here}(a, 0, i);
    loop invariant unchanged: Unchanged{Pre,Here}(a, i, n);
    loop assigns   i, a[0..n-1];
    loop variant   n - i;
  */
  for (size_type i = 0; i < n; ++i) {
    const size_type k = upper_bound(a, i, a[i]);
    //@ assert bound:   0 <= k <= i;

    /*@
       requires sorted:  UpperBound(a, k, a[i]);
       requires sorted:  StrictLowerBound(a, k, i, a[i]);
       requires sorted:  Sorted(a, k, i);

       assigns a[k..i];

       ensures unchanged: Unchanged{Old,Here}(a, 0, k);
       ensures unchanged: Unchanged{Old,Here}(a, i+1, n);
       ensures reorder:   MultisetUnchanged{Old,Here}(a, 0, k);
       ensures reorder:   EqualRanges{Old,Here}(a, k, i, k+1);
       ensures reorder:   EqualRanges{Old,Here}(a, i, i+1, k);
       ensures sorted:    Sorted(a, 0, k);
       ensures sorted:    UpperBound(a, k, a[k]);
    */
    rotate(a + k, i - k, i - k + 1);

    //@ assert sorted:  Sorted(a, k+1, i+1);
    //@ assert sorted:  StrictLowerBound(a, k+1, i+1, a[k]);
    //@ assert sorted:  Sorted(a, i+1);

    //@ assert reorder: MultisetUnchanged{Pre,Here}(a, 0, i+1);
  }
}

