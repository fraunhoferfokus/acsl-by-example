
#include "remove_copy3.h"
#include "At.acsl"

size_type
remove_copy3(const value_type* a, size_type n, value_type* b, value_type v)
{
  size_type k = 0u;

  /*@
    loop invariant size:       k == CountNotEqual{Pre}(a,i,v);
    loop invariant bound:      0 <= k <= i <= n;
    loop invariant remove:     Remove{Pre,Here}(a, n, i, b, v);
    loop invariant discard:    NoneEqual(b, k, v);
    loop invariant interval:   RemovePartition{Pre}(a, n, v, k-1) <= i;
    loop invariant interval:   i <= RemovePartition{Pre}(a, n, v, k);
    loop invariant unchanged:  Unchanged{Pre,Here}(a, n);
    loop invariant unchanged:  Unchanged{Pre,Here}(b, k, n);
    loop assigns   k, i, b[0..n-1];
    loop variant   n-i;
  */
  for (size_type i = 0u; i < n; ++i) {
    if (a[i] != v) {
      b[k++] = a[i];
      //@ assert size:      k == CountNotEqual{Pre}(a, i+1, v);
      //@ assert update:    b[k-1] == At{Pre}(a, i);
      //@ assert interval:  i == RemovePartition{Pre}(a, n, v, k-1);
      //@ assert remove:    Remove{Pre,Here}(a, n, i, b, v);
      //@ assert remove:    Remove{Pre,Here}(a, n, i+1, b, v);
      //@ assert unchanged: Unchanged{Pre,Here}(a, n);
      //@ assert unchanged: Unchanged{Pre,Here}(b, k, n);
    }
    else {
      //@ assert unchanged: Unchanged{Pre,Here}(a, n);
    }

    //@ assert unchanged: Unchanged{Pre,Here}(a, n);
  }

  return k;
}

