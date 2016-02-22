
#include "lower_bound.h"

size_type
lower_bound(const value_type* a, size_type n, value_type val)
{
  size_type left = 0;
  size_type right = n;
  size_type middle = 0;

  /*@
    loop invariant bound:  0 <= left <= right <= n;
    loop invariant left:   StrictUpperBound(a, 0,  left, val);
    loop invariant right:  LowerBound(a, right, n, val);

    loop assigns middle, left, right;
    loop variant right - left;
  */
  while (left < right) {
    middle = left + (right - left) / 2;

    if (a[middle] < val) {
      left = middle + 1;
    } else {
      right = middle;
    }
  }

  return left;
}

