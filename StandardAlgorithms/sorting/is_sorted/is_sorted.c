
#include "is_sorted.h"
#include "IncreasingLemmas.spec"

bool
is_sorted(const value_type* a, size_type n)
{
  if (0u < n) {
    /*@
        loop invariant increasing: WeaklyIncreasing(a, i+1);
        loop assigns i;
        loop variant n - i;
    */
    for (size_type i = 0u; i < n - 1u; ++i) {
      if (a[i] > a[i + 1u]) {
        return false;
      }
    }
  }

  return true;
}

