
#include "swap_ranges.h"
#include "../swap/swap.h"
#include "Unchanged.h"

void swap_ranges(value_type* a, size_type n, value_type* b)
{
  /*@
    loop invariant bound:  0 <= i <= n;
    loop invariant equal:  EqualRanges{Pre,Here}(a, i, b);
    loop invariant equal:  EqualRanges{Pre,Here}(b, i, a);

    loop invariant unchanged:  Unchanged{Pre,Here}(a, i, n);
    loop invariant unchanged:  Unchanged{Pre,Here}(b, i, n);

    loop assigns i, a[0..n-1], b[0..n-1];
    loop variant n-i;
  */
  for (size_type i = 0; i < n; ++i) {
    swap(a + i, b + i);
  }
}

