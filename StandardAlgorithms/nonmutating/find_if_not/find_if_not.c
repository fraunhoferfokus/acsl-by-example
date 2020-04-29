
#include "find_if_not.h"


size_type
find_if_not(const value_type* a, size_type n, value_type v)
{
  /*@
    loop invariant bound:     0 <= i <= n;
    loop invariant not_found: FindNotEqual(a, i, v) == i;
    loop assigns i;
    loop variant n-i;
   */
  for (size_type i = 0u; i < n; i++) {
    if (a[i] != v) {
      //@ assert found: FindNotEqual(a, n, v) == i;
      return i;
    }
  }

  return n;
}

