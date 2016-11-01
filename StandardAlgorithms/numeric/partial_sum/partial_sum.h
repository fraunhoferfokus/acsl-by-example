
#ifndef PARTIAL_SUM_H_INCLUDED
#define PARTIAL_SUM_H_INCLUDED

#include "PartialSum.h"
#include "AccumulateBounds.h"

/*@
  requires valid:     \valid_read(a + (0..n-1));
  requires valid:     \valid(b + (0..n-1));
  requires separated: \separated(a + (0..n-1), b + (0..n-1));
  requires bounds:    AccumulateBounds(a, n+1);

  assigns b[0..n-1];

  ensures result:     \result == n;
  ensures partialsum: PartialSum(a, n, b);
  ensures unchanged:  Unchanged{Here,Pre}(a, n);
*/
size_type
partial_sum(const value_type* a, size_type n, value_type* b);

#endif /* PARTIAL_SUM_H_INCLUDED */

