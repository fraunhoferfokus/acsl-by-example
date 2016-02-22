
#include "count.h"

size_type
count(const value_type* a, size_type n, value_type val)
{
  size_type counted = 0;

  /*@
    loop invariant 0 <= i <= n;
    loop invariant 0 <= counted <= i;
    loop invariant counted == Count(a, i, val);
    loop assigns i, counted;
    loop variant n-i;
  */
  for (size_type i = 0; i < n; ++i) {
    if (a[i] == val) {
      counted++;
    }
  }

  return counted;
}

