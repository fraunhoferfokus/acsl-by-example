
#include "find.h"

size_type
find(const value_type* a, size_type n, value_type v)
{
  /*@
    loop invariant 0 <= i <= n;
    loop invariant \forall integer k; 0 <= k < i ==> a[k] != v;
    loop assigns i;
    loop variant n-i;
   */
  for (size_type i = 0u; i < n; i++) {
    if (a[i] == v) {
      return i;
    }
  }

  return n;
}

