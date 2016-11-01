
#include "search.h"
#include "../equal/equal.h"

size_type search(const value_type* a, size_type m,
                 const value_type* b, size_type n)
{
  if (n > m) {
    return m;
  }

  /*@
    loop invariant bound:     i <= m-n+1;
    loop invariant not_found: !HasSubRange(a, 0, n+i-1, b, n);
    loop assigns i;
    loop variant m-i;
  */
  for (size_type i = 0; i <= m - n; ++i) {
    if (equal(a + i, n, b)) {
      return i;
    }
  }

  return m;
}

