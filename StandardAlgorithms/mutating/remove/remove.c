
#include "remove.h"
#include "At.spec"

size_type
remove(value_type* a, size_type n, value_type v)
{
  size_type k = 0u;

  /*@
    loop invariant size:       k == CountNotEqual{Pre}(a,i,v);
    loop invariant bound:      0 <= k <= i <= n;
    loop invariant remove:     Remove{Pre,Here}(a, i, v);
    loop invariant mapping:    i <= RemovePartition{Pre}(a, n, v, k);
    loop invariant unchanged:  Unchanged{Pre,Here}(a, k, n);
    loop invariant unchanged:  a[k] == At{Pre}(a, k);
    loop assigns k, i, a[0..n-1];
    loop variant n-i;
  */
  for (size_type i = 0u; i < n; ++i ) {
    if (a[i] != v) {
      a[k++] = a[i];
      //@ assert size:    k == CountNotEqual{Pre}(a, 0, i+1, v);
      //@ assert mapping: i == RemovePartition{Pre}(a, n, v, k-1);
      //@ assert update:  a[k-1] == At{Pre}(a, RemovePartition{Pre}(a, i+1, v, k-1));
      //@ assert remove:  Remove{Pre,Here}(a, i, v);
      //@ assert remove:  Remove{Pre,Here}(a, i+1, v);
    }
  }

  return k;
}
