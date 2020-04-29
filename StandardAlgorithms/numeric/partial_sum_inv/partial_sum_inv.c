
#include "partial_sum.h"
#include "adjacent_difference.h"
#include "DefaultBounds.acsl"
#include "NumericInverse.acsl"

/*@
  requires valid:     \valid(a + (0..n-1));
  requires valid:     \valid(b + (0..n-1));
  requires sep:       \separated(a + (0..n-1), b + (0..n-1));
  requires bounds:    AccumulateDefaultBounds(a, n);
  requires bounds:    DefaultBounds(a, n);
  assigns             a[0..n-1], b[0..n-1];
  ensures unchanged:  Unchanged{Pre,Here}(a, n);
*/
void
partial_sum_inv(value_type* a, size_type n, value_type* b)
{
  partial_sum(a, n, b);
  adjacent_difference(b, n, a);
}

