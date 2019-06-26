
#include "find2.h"

size_type
find2(const value_type* a, size_type n, value_type val)
{
  /*@
    loop invariant bound:     0 <= i <= n;
    loop invariant not_found: !HasValue(a, i, val);
    loop assigns i;
    loop variant n-i;
   */
  for (size_type i = 0u; i < n; i++) {
    if (a[i] == val) {
      return i;
    }
  }

  return n;
}

