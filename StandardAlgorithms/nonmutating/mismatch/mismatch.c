
#include "mismatch.h"

size_type mismatch(const value_type* a, size_type n,
                   const value_type* b)
{
  /*@
    loop invariant 0 <= i <= n;
    loop invariant EqualRanges{Here,Here}(a, i, b);
    loop assigns i;
    loop variant n-i;
  */
  for (size_type i = 0; i < n; i++)
    if (a[i] != b[i])
    {
      return i;
    }

  return n;
}

