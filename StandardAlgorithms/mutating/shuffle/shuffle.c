
#include "shuffle.h"
#include "random_number.h"
#include "swap.h"
#include "MultisetReorder.acsl"
#include "MultisetSwap.acsl"


void
shuffle(value_type* a, size_type n, unsigned short* seed)
{
  if (0u < n) {
    /*@
      loop invariant bounds:    1 <= i <= n;
      loop invariant reorder:   MultisetReorder{Pre,Here}(a, 0, i);
      loop invariant unchanged: Unchanged{Pre,Here}(a, i, n);
      loop assigns   i, a[0..n-1], seed[0..2];
      loop variant   n - i;
    */
    for (size_type i = 1u; i < n; ++i) {
      size_type k = random_number(seed, i) + 1u;

      //@ assert less: 0 <= k <= i;
      if (k < i) {
        swap(&a[k], &a[i]);
        //@ assert swapped: ArraySwap{LoopCurrent,Here}(a, k, i, n);
        //@ assert reorder: MultisetReorder{LoopCurrent,Here}(a, i+1);
        //@ assert reorder: MultisetReorder{Pre,Here}(a, i+1);
      }
      else {
        //@ assert unchanged: Unchanged{LoopCurrent,Here}(a, i+1);
        //@ assert reorder:   MultisetReorder{Pre,Here}(a, i+1);
      }

      //@ assert reorder: MultisetReorder{Pre,Here}(a, i+1);
    }
  }
}

