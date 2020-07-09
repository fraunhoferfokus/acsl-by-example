
#ifndef UPPER_BOUND_H_INCLUDED
#define UPPER_BOUND_H_INCLUDED

#include "Increasing.acsl"
#include "ArrayBounds.acsl"

/*@
  requires valid:      \valid_read(a + (0..n-1));
  requires increasing: Increasing(a, n);
  assigns              \nothing;
  ensures result:      0 <= \result <= n;
  ensures left:        UpperBound(a, 0, \result, v);
  ensures right:       StrictLowerBound(a, \result, n, v);
*/
size_type
upper_bound(const value_type* a, size_type n, value_type v);

#endif /* UPPER_BOUND_H_INCLUDED */

