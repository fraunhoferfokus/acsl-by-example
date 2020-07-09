
#include "heap_child_max.h"

size_type
heap_child_max(const value_type* a, size_type n, size_type p)
{
  if (p + 2 <= n - p) {
    const size_type left  = 2u * p + 1;
    const size_type right = left + 1u;

    if (right < n) {
      // case of two children: select child with maximum value
      return a[right] <= a[left] ? left : right;
    }
    else {
      // at most one child that comes before n-1 can exist
      return left;
    }
  }
  else {
    return n;
  }
}

