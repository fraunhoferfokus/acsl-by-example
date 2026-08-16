#include "find_last.h"

size_type find_last(const value_type* a, size_type n, value_type v)
{
  size_type r = n;

  /*@
    loop invariant bound: 0 <= i <= n;
    loop invariant index: r == n || 0 <= r < i;
    loop invariant none:  r == n ==> NoneEqual(a, i, v);
    loop invariant bound: r < n ==> 0 <= r < i;
    loop invariant hit:   r < n ==> a[r] == v;
    loop invariant last:  r < n ==> NoneEqual(a, r+1, i, v);
    loop assigns i, r;
    loop variant n-i;
   */
  for (size_type i = 0u; i < n; ++i) {
    if (a[i] == v) {
      r = i;
    }
  }

  return r;
}
