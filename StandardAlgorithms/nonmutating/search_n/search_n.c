
#include "search_n.h"

size_type
search_n(const value_type* a, size_type m, size_type n, value_type b)
{
  if (0u < n) {

    if (n <= m) {

      size_type start = 0;

      /*@
        loop invariant constant:  ConstantRange(a, start, i, b);
        loop invariant start:     0 < start ==> a[start-1] != b;
        loop invariant bound:     start <= i + 1;
        loop invariant not_found: !HasConstantSubRange(a, i, n, b);
        loop assigns i, start;
        loop variant m - i;
      */
      for (size_type i = 0; i < m; ++i) {
        if (a[i] != b) {
          start = i + 1;
        }
        else if (n == i + 1 - start) {
          return start;
        }
      }
    }

    return m;
  }
  return 0;
}

