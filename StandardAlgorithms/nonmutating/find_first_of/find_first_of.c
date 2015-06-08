#include "nonmutating.h"

size_type find_first_of (const value_type* a, size_type m,
                         const value_type* b, size_type n)
{
  /*@
    loop invariant bound: 0 <= i <= m;
    loop invariant not_found: !HasValueOf(a, i, b, n);
    loop assigns i;
    loop variant m-i;
  */
  for (size_type i = 0; i < m; i++)
  {
    if (find(b, n, a[i]) < n)
    {
      return i;
    }
  }

  return m;
}

