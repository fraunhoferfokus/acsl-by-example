
#include "count2.h"
#include "CountIndLemmas.acsl"

size_type
count2(const value_type* a, size_type n, value_type v)
{
  size_type counted = 0u;

  /*@
    loop invariant bound: 0 <= i <= n;
    loop invariant bound: 0 <= counted <= i;
    loop invariant count: CountInd(a, i, v, counted);
    loop assigns i, counted;
    loop variant n-i;
  */
  for (size_type i = 0u; i < n; ++i) {
    if (a[i] == v) {
      counted++;
      //@ assert count: CountInd(a, i+1, v, counted);
    }
  }

  return counted;
}

