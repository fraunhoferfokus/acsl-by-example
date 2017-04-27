
#include "../swap/swap.h"
#include "random_shuffle.h"
#include "CountLemmas.h"

#include "random_number.c"

void random_shuffle(value_type* a, size_type n)
{
  if (n > 0) {

    /*@
      loop invariant bounds:    1 <= i <= n;
      loop invariant reorder:   MultisetUnchanged{Here,Pre}(a,0,i);
      loop invariant unchanged: Unchanged{Here,Pre}(a,i,n);
      loop assigns   i, a[0..n-1], random_seed[0..2];
      loop variant   n - i;
    */
    for (size_type i = 1; i < n; ++i) {
      const size_type j = random_number(i) + 1;

      //@ ghost Before:
      swap(&a[j], &a[i]);
      //@ assert reorder: MultisetUnchanged{Here,Before}(a, 0, j);
      //@ assert reorder: MultisetUnchanged{Here,Before}(a, j+1, i);
    }
  }
}

