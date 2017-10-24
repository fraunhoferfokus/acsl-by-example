
#include "reverse.h"
#include "Unchanged.h"
#include "../swap/swap.h"

void reverse(value_type* a, size_type n)
{
  const size_type half = n / 2u;
  /*@
    loop invariant bound: 0 <= i <= half;

    loop invariant left:     Reverse{Pre,Here}(a, 0, i, n-i);
    loop invariant middle: Unchanged{Pre,Here}(a, i, n-i);
    loop invariant right:    Reverse{Pre,Here}(a, n-i, n, 0);

    loop assigns i, a[0..n-1];
    loop variant half - i;
  */
  for (size_type i = 0u; i < half; ++i) {
    swap(&a[i], &a[n - 1u - i]);
  }
}

