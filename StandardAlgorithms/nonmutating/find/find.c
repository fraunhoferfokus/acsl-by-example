
#include "find.h"

size_type find(const value_type* a, size_type n, value_type val)
{
  /*@
    loop invariant 0 <= i <= n;
    loop invariant \forall integer k; 0 <= k < i ==> a[k] != val;
    loop assigns i;
    loop variant n-i;
   */
  for (size_type i = 0; i < n; i++) {
    if (a[i] == val) {
      return i;
    }
  }

  return n;
}

