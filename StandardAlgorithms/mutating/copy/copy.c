
#include "copy.h"

void copy(const value_type* a, size_type n, value_type* b)
{
  /*@
    loop invariant bound:      0 <= i <= n;
    loop invariant equal:     EqualRanges{Here,Pre}(b, i, a);
    loop invariant unchanged:   Unchanged{Here,Pre}(a, i, n);
    loop assigns   i, b[0..n-1];
    loop variant n-i;
  */
  for (size_type i = 0; i < n; ++i) {
    b[i] = a[i];
  }
}

