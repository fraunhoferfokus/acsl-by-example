
#include "reverse_copy.h"

void reverse_copy(const value_type* a, size_type n, value_type* b)
{
  /*@
    loop invariant bound:   0 <= i <= n;
    loop invariant reverse: Reverse{Here,Here}(b, n, a, 0, i);
    loop assigns i, b[0..n-1];
    loop variant n-i;
  */
  for (size_type i = 0; i < n; ++i) {
    b[i] = a[n - 1 - i];
  }
}

