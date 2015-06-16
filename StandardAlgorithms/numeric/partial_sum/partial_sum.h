
#ifndef PARTIAL_SUM_H_INCLUDED
#define PARTIAL_SUM_H_INCLUDED

#include "PartialSum.h"
#include "limits.h"

/*@
  requires valid_in:   \valid_read(a + (0..n-1));
  requires valid_out:  \valid(b + (0..n-1));
  requires separated:  \separated(a + (0..n-1), b + (0..n-1));
  requires bounds:     \forall integer i; 0 <= i < n ==>
                       INT_MIN <= Accumulate(a, i) + a[i] <= INT_MAX;

  assigns b[0..n-1];

  ensures result:      \result == n;
  ensures partialsum:  PartialSum(a, n, b);
  ensures unchanged:   EqualRanges{Here,Pre}(a, n, a);
*/
size_type
partial_sum(const value_type* a, size_type n, value_type* b);

#endif /* PARTIAL_SUM_H_INCLUDED */

