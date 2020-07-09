
#ifndef LOWER_H_BOUND_INCLUDED
#define LOWER_H_BOUND_INCLUDED

#include "Increasing.acsl"
#include "ArrayBounds.acsl"

/*@
  requires valid:      \valid_read(a + (0..n-1));
  requires increasing: Increasing(a, n);
  assigns              \nothing;
  ensures result:      0 <= \result <= n;
  ensures left:        StrictUpperBound(a, 0, \result, v);
  ensures right:       LowerBound(a, \result, n, v);
*/
size_type
lower_bound(const value_type* a, size_type n, value_type v);

#endif /* LOWER_H_BOUND_INCLUDED */

