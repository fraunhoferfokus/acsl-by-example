
#include "mutating.h"

void reverse(value_type* a, size_type n)
{
  const size_type half = n / 2;

  /*@
    loop invariant bound: 0 <= i <= half;

    loop invariant left:   Reversed{Here,Pre} (a, n, a, 0,  i);
    loop invariant middle: Unchanged{Here,Pre}(a, i, n - i);
    loop invariant right:  Reversed{Here,Pre} (a, n, a, n-i, n);

    loop assigns i, a[0..n-1];
    loop variant half - i;
  */
  for (size_type i = 0; i < half; ++i)
  {
    //@ assert 0 < half ==> i < n-1-i;
    swap(&a[i], &a[n-1-i]);
  }
}

