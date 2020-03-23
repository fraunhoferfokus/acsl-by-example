
#include "selection_sort.h"
#include "min_element.h"
#include "swap.h"
#include "ShiftLemmas.spec"
#include "MultisetUnchanged.spec"
#include "SwappedInside.spec"

void
selection_sort(value_type* a, size_type n)
{
  /*@
    loop invariant bound:       0 <= i <= n;
    loop invariant reorder:     MultisetUnchanged{Pre,Here}(a, n);
    loop invariant increasing:  Increasing(a, i);
    loop invariant increasing:  0 < i  ==> LowerBound(a, i, n, a[i-1]);
    loop assigns   i, a[0..n-1];
    loop variant   n - i;
  */
  for (size_type i = 0u; i < n; ++i) {
    const size_type sel = i + min_element(a + i, n - i);

    if (i < sel) {
      /*@
         assigns          a[sel], a[i];
         ensures swapped: SwappedInside{Old,Here}(a, i, sel, n);
      */
      swap(a + sel, a + i);
    }

    //@ assert reorder: MultisetUnchanged{LoopCurrent,Here}(a, n);
    //@ assert reorder: MultisetUnchanged{Pre,Here}(a, n);
  }
}

