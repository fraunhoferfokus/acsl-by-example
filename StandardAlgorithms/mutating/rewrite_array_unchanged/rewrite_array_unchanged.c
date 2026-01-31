
#include "rewrite_array_unchanged.h"

void rewrite_array(value_type* a, size_type n)
{
  /*@
    loop invariant 0u <= i <= n;
    loop invariant array_prefix: Unchanged{Pre,Here}(a, 0, i);
    loop invariant array_suffix: Unchanged{Pre,Here}(a, i, n);
    loop assigns i, a[0..n-1];
    loop variant n - i;
  */
  for (size_type i = 0u; i < n; i++) {
    a[i] = a[i];
  }
}

