
#include "iota.h"

void iota(value_type* a, size_type n, value_type val)
{
  /*@
    loop invariant bound:     0 <= i <= n;
    loop invariant increment: val == \at(val, Pre) + i;
    loop invariant previous:  \forall integer k; 0 <= k < i
                    ==> a[k] == \at(val, Pre) + k;

    loop assigns i, val, a[0..n-1];
    loop variant n-i;
  */
  for (size_type i = 0; i < n; ++i)
  {
    a[i] = val++;
  }
}
