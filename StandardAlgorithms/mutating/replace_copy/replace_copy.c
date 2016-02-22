
#include "replace_copy.h"

size_type replace_copy(const value_type* a, size_type n,
                       value_type* b,
                       value_type  oldv, value_type newv)
{
  /*@
    loop invariant bounds:  0 <= i <= n;
    loop invariant replace: Replace{Pre,Here}(a, i, b, oldv, newv);
    loop assigns i, b[0..n-1];
    loop variant n-i;
  */
  for (size_type i = 0; i < n; ++i) {
    b[i] = (a[i] == oldv ? newv : a[i]);
  }

  return n;
}

