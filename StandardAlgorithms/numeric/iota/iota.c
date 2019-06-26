
#include "iota.h"

void
iota(value_type* a, size_type n, value_type val)
{
  /*@
    loop invariant bound:     0 <= i <= n;
    loop invariant limit:     val == \at(val, Pre) + i;
    loop invariant increment: Iota(a, i, \at(val, Pre));

    loop assigns i, val, a[0..n-1];
    loop variant n-i;
  */
  for (size_type i = 0u; i < n; ++i) {
    a[i] = val++;
  }
}
