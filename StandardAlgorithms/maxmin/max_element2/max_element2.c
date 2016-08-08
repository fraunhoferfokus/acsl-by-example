
#include "max_element2.h"

size_type max_element(const value_type* a, size_type n)
{
  if (n == 0) {
    return 0;
  }

  size_type max = 0;
  /*@
    loop invariant bound:   0 <= i <= n;
    loop invariant max:     0 <= max < n;
    loop invariant upper:   UpperBound(a, 0, i, a[max]);
    loop invariant strict:  StrictUpperBound(a, 0, max, a[max]);
    loop assigns max, i;
    loop variant n-i;
  */
  for (size_type i = 0; i < n; i++) {
    if (a[max] < a[i]) {
      max = i;
    }
  }
  return max;
}

