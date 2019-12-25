
#include "unique_copy4.h"
#include "UniquePreserve.spec"

size_type
unique_copy4(const value_type* a, size_type n, value_type* b)
{
  if (0u < n) {
    size_type k = 0u;
    b[k] = a[0];
    //@ assert mapping:   0 == UniquePartition(a, n, k);

    /*@
      loop invariant bound:     0 <= k < i <= n;
      loop invariant size:      k+1 == UniqueSize(a, i);
      loop invariant copy:      b[k] == a[i-1];
      loop invariant mapping:   UniquePartition(a, n, k) < i;
      loop invariant mapping:   i <= UniquePartition(a, n, k+1);
      loop invariant unique:    Unique(a, i, b);
      loop invariant unchanged: Unchanged{Pre, Here}(a, n);
      loop invariant unchanged: Unchanged{Pre, Here}(b, k+1, n);
      loop assigns i, k, b[0..n-1];
      loop variant n-i;
    */
    for (size_type i = 1u; i < n; ++i) {
      const value_type val = a[i];

      if (b[k] != val) {
        //@ assert distinct:  a[i-1] != a[i];
        b[++k] = val;
        //@ assert unchanged: Unchanged{LoopCurrent,Here}(b, k);
        //@ assert unchanged: Unchanged{LoopCurrent,Here}(a, n);
        //@ assert unchanged: Unchanged{LoopCurrent,Here}(a, i);
        //@ assert mapping:   i == UniquePartition(a, n, k);
        //@ assert size:      k == UniqueSize(a, i);
        //@ assert unique:    Unique(a, i, b);
      }

      //@ assert mapping:   i <= UniquePartition(a, n, k+1);
      //@ assert unchanged: Unchanged{Pre, Here}(b, k+1, n);
    }

    return ++k;
  }
  else {
    return n;
  }
}

