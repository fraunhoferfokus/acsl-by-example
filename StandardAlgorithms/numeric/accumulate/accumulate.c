
#include "accumulate.h"

value_type
accumulate(const value_type* a, size_type n, value_type init)
{
  value_type result = init;

  /*@
     loop invariant index:    0 <= i <= n;
     loop invariant partial:  result == Accumulate(a, i, init);
     loop assigns i, result;
     loop variant n-i;
  */
  for (size_type i = 0; i < n; ++i)
  {
    result = result + a[i];
  }

  return result;
}

