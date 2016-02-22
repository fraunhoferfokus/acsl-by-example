
#include "partial_sum.h"
#include "PartialSumLemmas.h"

size_type
partial_sum(const value_type* a, size_type n, value_type* b)
{
  if (n > 0) {
    b[0] = a[0];

    /*@
       loop invariant bound:      1 <= i <= n;
       loop invariant unchanged:  Unchanged{Here,Pre}(a, n);
       loop invariant accumulate: b[i-1] == Accumulate(a, i);
       loop invariant partialsum: PartialSum(a, i, b);
       loop assigns i, b[1..n-1];
       loop variant n - i;
    */
    for (size_type i = 1u; i < n; ++i) {
      //@ ghost Enter:
      b[i] = b[i - 1u] + a[i];
      //@ assert unchanged:  a[i] == \at(a[i],Enter);
      //@ assert unchanged:  Unchanged{Enter,Here}(a, i);
      //@ assert unchanged:  Unchanged{Enter,Here}(b, i);
    }
  }

  return n;
}

