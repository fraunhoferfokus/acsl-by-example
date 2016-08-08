
#include "remove.h"
#include "HasValueLemmas.h"

size_type remove(value_type* a, size_type n, value_type v)
{
  size_type j = 0;

  /*@
    loop invariant bound:      0 <= j <= i <= n;
    loop invariant size:       j == i - Count{Pre}(a, i, v);
    loop invariant retain:     MultisetRetainRest{Pre,Here}(a, i, a, j, v);
    loop invariant discard:    !HasValue(a, j, v);
    loop invariant unchanged:  Unchanged{Here,Pre}(a, j, n);
    loop assigns i, j, a[0..n-1];
    loop variant n-i;
  */
  for (size_type i = 0; i < n; ++i) {
    if (a[i] != v) {
      a[j++] = a[i];
      //@  assert retain: MultisetRetainRest{Pre,Here}(a, i+1, a, j, v);
    }
  }

  return j;
}

