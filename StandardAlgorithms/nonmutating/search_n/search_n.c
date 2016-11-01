
#include "search_n.h"

size_type
search_n(const value_type* a, size_type m, size_type n, value_type b)
{
  if (m <= 0 || n <= 0) {
    return 0;
  }

  if (m < n) {
    return m;
  }

  size_type start = 0;

  /*@
    loop invariant constant:  ConstantRange(a, start, i, b);
    loop invariant start:     start == 0 || !ConstantRange(a, start-1, i, b);
    loop invariant not_found: !HasConstantSubRange(a, i, n, b);
    loop assigns i, start;
    loop variant m - i;
  */
  for (size_type i = 0; i < m; ++i) {
    if (a[i] != b) {
      start = i + 1;
    } else if (i + 1 - start >= n) {
      return start;
    }
  }

  return m;
}

