#include "adjacent_find.h"

size_type
adjacent_find(const value_type* a, size_type n)
{
  if (n > 1u) {
    /*@
      loop invariant bound:   1 <= i <= n;
      loop invariant not_yet: !HasEqualNeighbors(a, i);
      loop assigns i;
      loop variant n-i;
    */
    for (size_type i = 1; i < n ; i++) {
      if (a[i] == a[i - 1]) {
        return i - 1;
      }
    }
  }

  return n;
}

