
#include "remove_copy3.h"
#include "RemoveSizePreserve.spec"

size_type
remove_copy3(const value_type* a, size_type n, value_type* b, value_type v)
{
  size_type k = 0u;

  /*@
    loop invariant bound:     0 <= k <= i <= n;
    loop invariant size:      k == RemoveSize{Pre}(a, i, v);
    loop invariant mapping:   i <= RemovePartition{Pre}(a, n, v, k);
    loop invariant remove:    Remove{Pre,Here}(a, i, b, v);
    loop invariant unchanged: Unchanged{Pre,Here}(a, n);
    loop invariant unchanged: Unchanged{Pre,Here}(b, k, n);
    loop assigns   k, i, b[0..n-1];
    loop variant   n-i;
  */
  for (size_type i = 0u; i < n; ++i) {
    if (a[i] != v) {
      b[k++] = a[i];
      //@ assert mapping: RemovePartition{Pre}(a, n, v, k) == i;
    }
  }

  return k;
}

