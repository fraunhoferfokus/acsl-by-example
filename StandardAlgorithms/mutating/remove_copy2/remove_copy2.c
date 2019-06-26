
#include "remove_copy2.h"
#include "RemoveSizePreserve.spec"

size_type
remove_copy2(const value_type* a, size_type n, value_type* b, value_type v)
{
  size_type k = 0u;

  /*@
    loop invariant size:      k == RemoveSize(a, i, v);
    loop invariant bound:     0 <= k <= i <= n;
    loop invariant discard:   !HasValue(b, k, v);
    loop invariant unchanged: Unchanged{Pre,Here}(b, k, n);
    loop assigns   k, i, b[0..n-1];
    loop variant   n-i;
  */
  for (size_type i = 0u; i < n; ++i) {
    if (a[i] != v) {
      b[k++] = a[i];
    }
  }

  return k;
}

