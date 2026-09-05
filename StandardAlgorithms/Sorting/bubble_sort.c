
#include "bubble_sort.h"
#include "swap.h"
#include "ArrayExtrema.acsl"
#include "MultisetSwap.acsl"
#include "IncreasingLemmas.acsl"

void bubble_sort(value_type* a, size_type n)
{
  if (0 < n) {
    /*@
      loop invariant bound:          1 <= i <= n;
      loop invariant increasing:     WeaklyIncreasing(a, n-i+1, n);
      loop invariant upper:          1 < i ==> UpperBound(a, n-i+1, a[n-i+1]);
      loop invariant reorder:        MultisetReorder{Pre,Here}(a, n);
      loop assigns i, a[0..n-1];
      loop variant n-i;
    */
    for (size_type i = 1u; i < n; ++i) {
      /*@
        loop invariant bound:        0 <= j <= n-i;
        loop invariant increasing:   WeaklyIncreasing(a, n-i+1, n);
        loop invariant upper:        1 < i ==> UpperBound(a, n-i+1, a[n-i+1]);
        loop invariant max:          MaxElement(a, j+1, j);
        loop invariant reorder:      MultisetReorder{LoopEntry,Here}(a, j+1);
        loop invariant unchanged:    Unchanged{LoopEntry,Here}(a, j+1, n);
        loop assigns                 j, a[0..n-1];
        loop variant n-j;
      */
      for (size_type j = 0u; j < n - i; ++j) {
        if (a[j] > a[j + 1u]) {
          //@ assert max:       MaxElement(a, j+1, j);
          //@ assert reorder:   MultisetReorder{LoopEntry,Here}(a, 0, j+1);
          //@ assert reorder:   MultisetReorder{LoopEntry,Here}(a, 0, j+2);
          swap(&a[j], &a[j + 1u]);
          //@ assert max:       MaxElement(a, j+2, j+1);
          //@ assert swapped:   a[j+1] == At{LoopCurrent}(a, j);
          //@ assert swapped:   a[j]   == At{LoopCurrent}(a, j+1);
          //@ assert unchanged: Unchanged{LoopCurrent,Here}(a, 0, j);
          //@ assert unchanged: Unchanged{LoopCurrent,Here}(a, j+2, n);
          //@ assert swapped:   ArraySwap{LoopCurrent,Here}(a, j, j+1, n);
          //@ assert reorder:   MultisetReorder{LoopCurrent,Here}(a, j, j+2);
        }
      }
    }
  }

  //@ assert increasing: Increasing(a, n);
}

