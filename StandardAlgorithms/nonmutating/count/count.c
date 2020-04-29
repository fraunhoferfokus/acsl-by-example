
#include "count.h"

size_type
count(const value_type* a, size_type n, value_type v)
{
  size_type counted = 0u;

  /*@
    loop invariant bound: 0 <= i <= n;
    loop invariant bound: 0 <= counted <= i;
    loop invariant count: counted == Count(a, i, v);
    loop assigns i, counted;
    loop variant n-i;
  */
  for (size_type i = 0u; i < n; ++i) {
    if (a[i] == v) {
      counted++;
    }
  }

  return counted;
}

