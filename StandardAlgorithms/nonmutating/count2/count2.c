
#include "count2.h"
#include "CountIndLemmas.spec"

size_type
count2(const value_type* a, size_type n, value_type val)
{
  size_type counted = 0u;

  /*@
    loop invariant bound: 0 <= i <= n;
    loop invariant bound: 0 <= counted <= i;
    loop invariant count: CountInd(a, i, val, counted);
    loop assigns i, counted;
    loop variant n-i;
  */
  for (size_type i = 0u; i < n; ++i) {
    if (a[i] == val) {
      counted++;
      //@ assert count: CountInd(a, i+1, val, counted);
    }
  }

  return counted;
}

