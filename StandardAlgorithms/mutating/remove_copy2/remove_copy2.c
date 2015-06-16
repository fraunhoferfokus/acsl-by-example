
#include "remove_copy2.h"
#include "RemoveCountLemmas.h"

size_type remove_copy(const value_type* a, size_type n,
                      value_type* b, value_type v)
{
  size_type j = 0;

  /*@
    loop invariant bound:      0 <= j <= i <= n;
    loop invariant result:     j == RemoveCount(a, i, v);
    loop invariant removed:    !HasValue(b, j, v);
    loop invariant kept:       PreserveCount(a, i, b, j, v);
    loop invariant unchanged:  Unchanged{Here,Pre}(b, j, n);
    loop invariant stable:     StableRemove(a, i, b, v);

    loop assigns i, j, b[0..n-1];
    loop variant n-i;
  */
  for (size_type i = 0; i < n; ++i)
  {
    //@ assert EqualRanges{Here,Pre}(a, n);
    if (a[i] != v)
    {
      b[j++] = a[i];
    }
  }

  return j;
}

