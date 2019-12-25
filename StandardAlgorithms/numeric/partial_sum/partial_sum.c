
#include "partial_sum.h"
#include "PartialSumLemmas.spec"

size_type
partial_sum(const value_type* a, size_type n, value_type* b)
{
  if (0u < n) {
    b[0u] = a[0u];

    /*@
       loop invariant bound:      1 <= i <= n;
       loop invariant unchanged:  Unchanged{Pre,Here}(a, n);
       loop invariant accumulate: b[i-1] == AccumulateDefault(a, i-1);
       loop invariant partialsum: PartialSum(a, i, b);
       loop assigns i, b[1..n-1];
       loop variant n - i;
    */
    for (size_type i = 1u; i < n; ++i) {
      b[i] = b[i - 1u] + a[i];
      //@ assert unchanged:  a[i] == \at(a[i],LoopCurrent);
      //@ assert unchanged:  Unchanged{LoopCurrent,Here}(a, i);
      //@ assert unchanged:  Unchanged{LoopCurrent,Here}(b, i);
    }
  }

  return n;
}

