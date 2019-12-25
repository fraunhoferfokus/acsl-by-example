#include "unique_copy3.h"

size_type
unique_copy3(const value_type* a, size_type n, value_type* b)
{
  if (0u < n) {
    size_type k = 0u;
    b[k] = a[0];

    /*@
      loop invariant bound:     0 <= k < i <= n;
      loop invariant solitary:  !HasEqualNeighbors(b, k+1);
      loop invariant unchanged: Unchanged{Pre, Here}(b, k+1, n);
      loop assigns i, k, b[0..n-1];
      loop variant n-i;
    */
    for (size_type i = 1; i < n; ++i) {
      const value_type val = a[i];

      if (b[k] != val) {
        b[++k] = val;
      }
    }

    return ++k;
  }
  else {
    return n;
  }
}


