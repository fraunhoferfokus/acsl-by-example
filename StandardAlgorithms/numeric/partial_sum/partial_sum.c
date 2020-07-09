
#include "partial_sum.h"

size_type
partial_sum(const value_type* a, size_type n, value_type* b)
{
  if (0u < n) {
    //@ assert limits:      AccumulateDefaultBounds(a, n);
    b[0u] = a[0u];
    //@ assert unchanged:   Unchanged{Pre,Here}(a, n);
    //@ assert limits:      AccumulateDefaultBounds(a, n);
    //@ assert accumulate:  b[0] == AccumulateDefault(a, 1);
    //@ assert partialsum:  PartialSum(a, 1, b);

    /*@
       loop invariant bound:      1 <= i <= n;
       loop invariant unchanged:  Unchanged{Pre,Here}(a, n);
       loop invariant accumulate: b[i-1] == AccumulateDefault(a, i);
       loop invariant limits:     AccumulateDefaultBounds(a, n);
       loop invariant partialsum: PartialSum(a, i, b);
       loop assigns i, b[1..n-1];
       loop variant n - i;
    */
    for (size_type i = 1u; i < n; ++i) {
      b[i] = b[i - 1u] + a[i];
      //@ assert unchanged:  Unchanged{LoopCurrent,Here}(b, i);
      //@ assert unchanged:  Unchanged{LoopCurrent,Here}(a, n);
      //@ assert partialsum: b[i] == AccumulateDefault(a, i+1);
      //@ assert limits:     AccumulateDefaultBounds(a, n);
    }
  }

  return n;
}

