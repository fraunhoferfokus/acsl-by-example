
#include "iota.h"

void
iota(value_type* a, size_type n, value_type v)
{
  /*@
    loop invariant bound:     0 <= i <= n;
    loop invariant limit:     v == \at(v, Pre) + i;
    loop invariant increment: IotaGenerate(a, i, \at(v, Pre));

    loop assigns i, v, a[0..n-1];
    loop variant n-i;
  */
  for (size_type i = 0u; i < n; ++i) {
    a[i] = v++;
  }
}
