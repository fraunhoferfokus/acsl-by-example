
#include "bubble_sort.h"
#include "swap.h"
#include "Unchanged.spec"
#include "ArrayExtrema.spec"
#include "SwappedInside.spec"

void
bubble_sort(value_type* a, size_type n)
{
  if (0 < n) {
    /*@
      loop invariant bound:          1 <= i <= n;
      loop invariant increasing:     Increasing(a, n-i+1, n);
      loop invariant upper:          1 < i ==> UpperBound(a, n-i+1, a[n-i+1]);
      loop invariant reorder:        MultisetUnchanged{Pre,Here}(a, n);
      loop assigns i, a[0..n-1];
      loop variant n-i;
    */
    for (size_type i = 1u; i < n; ++i) {
      /*@
        loop invariant bound:        0 <= j <= n-i;
        loop invariant increasing:   Increasing(a, n-i+1, n);
        loop invariant upper:        1 < i ==> UpperBound(a, n-i+1, a[n-i+1]);
        loop invariant max:          MaxElement(a, j+1, j);
        loop invariant reorder:      MultisetUnchanged{LoopEntry,Here}(a, j+1);
        loop invariant reorder:      Unchanged{LoopEntry,Here}(a, j+1, n);
        loop assigns                 j, a[0..n-1];
        loop variant n-j;
      */
      for (size_type j = 0u; j < n - i; ++j) {
        if (a[j] > a[j + 1]) {
          swap(&a[j], &a[j + 1]);
          //@ assert swapped: SwappedInside{LoopCurrent,Here}(a, j, j+1, n);
        }
      }
    }
  }
}

