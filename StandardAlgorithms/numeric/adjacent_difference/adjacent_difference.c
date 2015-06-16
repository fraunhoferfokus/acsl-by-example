
#include "adjacent_difference.h"

size_type
adjacent_difference(const value_type* a, size_type n, value_type* b)
{
  if (n > 0)
  {
    b[0] = a[0];

    /*@
       loop invariant index:     1 <= i <= n;
       loop invariant unchanged: EqualRanges{Here,Pre}(a, n);
       loop invariant previous:  PartialSum(b, i, a);
       loop assigns i, b[1..n-1];
       loop variant n - i;
    */
    for (size_type i = 1u; i < n; ++i)
    {
      b[i] = a[i] - a[i - 1u];
    }
  }

  return n;
}

