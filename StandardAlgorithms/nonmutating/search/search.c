
#include "nonmutating.h"

size_type search(const value_type* a, size_type m,
                 const value_type* b, size_type n)
{
  if ((n == 0) || (m == 0)) {
    return 0;
  }

  if (n > m) {
    return m;
  }

  /*@
    loop invariant bound:     0 <= i <= m-n+1;
    loop invariant not_found: !HasSubRange(a, n+i-1, b, n);
    loop assigns i;
    loop variant m-i;
  */
  for (size_type i = 0; i <= m - n; i++) {
    if (equal(a + i, n, b)) {
      return i;
    }
  }

  return m;
}

