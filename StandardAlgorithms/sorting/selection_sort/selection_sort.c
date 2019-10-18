
#include "selection_sort.h"
#include "min_element.h"
#include "swap.h"
#include "LowerBound.spec"
#include "ShiftLemmas.spec"
#include "SwapImpliesMultisetUnchanged.spec"

void
selection_sort(value_type* a, size_type n)
{
  /*@
    loop invariant bound:   0 <= i <= n;
    loop invariant sorted:  Sorted(a, i);
    loop invariant sorted:  0 < i  ==> LowerBound(a, i, n, a[i-1]);
    loop invariant reorder: MultisetUnchanged{Pre,Here}(a, n);
    loop assigns   i, a[0..n-1];
    loop variant   n - i;
  */
  for (size_type i = 0u; i < n; ++i) {
    const size_type sel = i + min_element(a + i, n - i);
    //@ assert reorder: i <= sel < n;
    /*@
       assigns a[sel], a[i];

       ensures reorder: a[i]   == \old(a[sel]);
       ensures reorder: a[sel] == \old(a[i]);
       ensures reorder: Unchanged{Old,Here}(a, 0,     i);
       ensures reorder: Unchanged{Old,Here}(a, i+1,   sel);
       ensures reorder: Unchanged{Old,Here}(a, sel+1, n);
    */
    swap(a + sel, a + i);
    //@ assert reorder: MultisetUnchanged{Pre,Here}(a, n);
  }
}

