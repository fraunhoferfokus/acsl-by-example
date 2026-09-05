
#include "is_sorted_until.h"
#include "IncreasingLemmas.acsl"

size_type is_sorted_until(const value_type* a, size_type n)
{
  /*@
      loop invariant bound:       1 <= i <= n+1;
      loop invariant increasing:  WeaklyIncreasing(a, i);
      loop assigns i;
      loop variant n - i;
  */
  for (size_type i = 1u; i < n; ++i) {
    if (a[i - 1u] > a[i]) {
      return i;
    }
  }

  return n;
}

