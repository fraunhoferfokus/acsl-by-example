#include "adjacent_find.h"

size_type
adjacent_find(const value_type* a, size_type n)
{
  if (n == 0) {
    return n;
  }

  /*@
    loop invariant 0 <= i < n;
    loop invariant !HasEqualNeighbors(a, i+1);
    loop assigns i;
    loop variant n-i;
  */
  for (size_type i = 0; i < n - 1; i++) {
    if (a[i] == a[i + 1]) {
      return i;
    }
  }

  return n;
}

