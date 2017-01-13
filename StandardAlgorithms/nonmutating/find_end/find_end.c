
#include "find_end.h"
#include "../equal/equal.h"

size_type find_end(const value_type* a, size_type m,
                   const value_type* b, size_type n)
{
  if (n == 0) {
    return m;
  }

  if (n > m) {
    return m;
  }

  size_type ret = m;

  /*@
    loop invariant bound:  ret <= m - n || ret == m;
    loop invariant result: ret == m ==> !HasSubRange(a, n+i-1, b, n);
    loop invariant result: ret < m  ==> EqualRanges{Here,Here}(a + ret, n, b);
    loop invariant last:   ret < m  ==> !HasSubRange(a, ret+1, i+n-1, b, n);
    loop assigns i, ret;
    loop variant m - i;
  */
  for (size_type i = 0; i <= m - n; ++i) {
    if (equal(a + i, n, b)) {
      ret = i;
    }
  }

  return ret;
}

