
#include "min_element.h"

size_type min_element(const value_type* a, size_type n)
{
  if (0 == n) {
    return n;
  }

  size_type min = 0;

  /*@
    loop invariant bound:   0 <= i   <= n;
    loop invariant min:     0 <= min <  n;
    loop invariant lower:   LowerBound(a, 0, i, a[min]);
    loop invariant first:   StrictLowerBound(a, 0, min, a[min]);

    loop assigns min, i;
    loop variant n-i;
  */
  for (size_type i = 0; i < n; i++) {
    if (a[i] < a[min]) {
      min = i;
    }
  }

  return min;
}

