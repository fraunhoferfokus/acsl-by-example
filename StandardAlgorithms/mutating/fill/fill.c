
#include "fill.h"

void fill(value_type* a, size_type n,  value_type val)
{
  /*@
    loop invariant bound:    0 <= i <= n;
    loop invariant constant: ConstantRange(a, i, val);
    loop assigns i, a[0..n-1];
    loop variant n-i;
  */
  for (size_type i = 0; i < n; ++i) {
    a[i] = val;
  }
}

