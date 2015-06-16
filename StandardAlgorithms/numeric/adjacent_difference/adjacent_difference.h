
#ifndef ADJACENT_DIFFERENCE_H_INCLUDED
#define ADJACENT_DIFFERENCE_H_INCLUDED

#include "PartialSum.h"
#include "limits.h"

/*@
   requires valid_in:   \valid_read(a + (0..n-1));
   requires valid_out:  \valid(b + (0..n-1));
   requires separated:  \separated(a + (0..n-1), b + (0..n-1));
   requires bounds:     \forall integer i; 1 <= i < n ==>
                        INT_MIN <= a[i] - a[i-1] <= INT_MAX;

   assigns b[0..n-1];

   ensures result:      \result == n;
   ensures partialsum:  PartialSum(b, n, a);
   ensures unchanged:   EqualRanges{Here,Pre}(a, n);
*/
size_type
adjacent_difference(const value_type* a, size_type n, value_type* b);

#endif /* ADJACENT_DIFFERENCE_H_INCLUDED */

