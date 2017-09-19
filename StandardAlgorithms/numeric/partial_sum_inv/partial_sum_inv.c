
#include "../partial_sum/partial_sum.h"
#include "../adjacent_difference/adjacent_difference.h"
#include "PartialSumInv.h"

/*@
  requires valid:     \valid(a + (0..n-1));
  requires valid:     \valid(b + (0..n-1));
  requires separated: \separated(a + (0..n-1), b + (0..n-1));
  requires bounds:    AccumulateBounds(a, n+1);

  assigns a[0..n-1], b[0..n-1];

  ensures unchanged:   Unchanged{Here,Pre}(a, n);
*/
void partial_sum_inv(value_type* a, size_type n, value_type* b)
{
  partial_sum(a, n, b);
  adjacent_difference(b, n, a);
}

