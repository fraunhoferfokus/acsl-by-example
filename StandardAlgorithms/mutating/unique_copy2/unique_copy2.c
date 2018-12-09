
#include "unique_copy2.h"
#include "UniquePreserve.h"


size_type
unique_copy(const value_type* a, size_type n, value_type* b)
{
  if (n == 0u) {
    return n;
  }
  else {
    size_type k = 0u;
    b[k] = a[0];
    //@ assert mapping:   0 == UniquePartition(a, n, k);

    /*@
      loop invariant bound:     0 <= k < i <= n;
      loop invariant size:      k+1 == UniqueSize(a, i);
      loop invariant copy:      b[k] == a[i-1];
      loop invariant mapping:   UniquePartition(a, n, k) < i;
      loop invariant mapping:   i <= UniquePartition(a, n, k+1);
      loop invariant range:     ConstantRange(a, UniquePartition(a, n, k), i);
      loop invariant unique:    Unique(a, i, b);
      loop invariant unchanged: Unchanged{Pre, Here}(b, k+1, n);
      loop assigns i, k, b[0..n-1];
      loop variant n-i;
    */
    for (size_type i = 1u; i < n; ++i) {
      const value_type val = a[i];
      if (b[k] != val) {
        //@ assert distinct:  a[i-1] != a[i];
        //@ ghost Before:
        b[++k] = val;
        //@ assert unchanged: Unchanged{Before,Here}(b, k);
        //@ assert unchanged: Unchanged{Before,Here}(a, n);
        //@ assert mapping:   i == UniquePartition(a, n, k);
        //@ assert range:     ConstantRange(a, UniquePartition(a, n, k), i+1);
        //@ assert size:      k == UniqueSize(a, i);
        //@ assert unique:    Unique(a, i, b);
      }
    }

    return ++k;
  }
}

