
#include "replace.h"
#include "Unchanged.h"

void replace(value_type* a, size_type n, value_type oldv, value_type newv)
{
  /*@
    loop invariant bounds:    0 <= i <= n;
    loop invariant replace:   Replace{Pre,Here}(a, i, oldv, newv);
    loop invariant unchanged: Unchanged{Pre,Here}(a, i, n);
    loop assigns i, a[0..n-1];
    loop variant n-i;
  */
  for (size_type i = 0; i < n; ++i) {
    if (a[i] == oldv) {
      a[i] = newv;
    }
  }
}

