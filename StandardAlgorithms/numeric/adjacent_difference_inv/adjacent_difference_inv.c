
#include "partial_sum.h"
#include "adjacent_difference.h"
#include "DefaultBounds.spec"
#include "NumericInverse.spec"


/*@
  requires size:      0 <= n;
  requires valid:     \valid(a + (0..n-1));
  requires valid:     \valid(b + (0..n-1));
  requires sep:       \separated(a + (0..n-1), b + (0..n-1));
  requires bounds:    DefaultBounds(a, n);
  requires bounds:    AdjacentDifferenceBounds(a, n);
  assigns             a[0..n-1], b[0..n-1];
  ensures unchanged:  Unchanged{Old,Here}(a, n);
*/
void
adjacent_difference_inv(value_type* a, size_type n, value_type* b)
{
  adjacent_difference(a, n, b);
  partial_sum(b, n, a);
}

