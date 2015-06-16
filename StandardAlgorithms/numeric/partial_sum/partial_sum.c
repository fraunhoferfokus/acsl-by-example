
#include "partial_sum.h"

size_type
partial_sum(const value_type* a, size_type n, value_type* b)
{
  if (n > 0)
  {
    b[0] = a[0];

    /*@
       loop invariant index:     1 <= i <= n;
       loop invariant unchanged: EqualRanges{Here,Pre}(a, n, a);
       loop invariant previous:  PartialSum(a, i, b);
       loop assigns i, b[1..n-1];
       loop variant n - i;
    */
    for (size_type i = 1; i < n; ++i)
    {
      b[i] = b[i - 1] + a[i];
    }
  }

  return n;
}

