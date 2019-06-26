
#ifndef UPPER_BOUND_H_INCLUDED
#define UPPER_BOUND_H_INCLUDED

#include "Sorted.spec"
#include "UpperBound.spec"
#include "StrictLowerBound.spec"

/*@
  requires valid:  \valid_read(a + (0..n-1));
  requires sorted: Sorted(a, n);

  assigns \nothing;

  ensures result:  0 <= \result <= n;
  ensures left:    UpperBound(a, 0, \result, val);
  ensures right:   StrictLowerBound(a, \result, n, val);
*/
size_type
upper_bound(const value_type* a, size_type n, value_type val);

#endif /* UPPER_BOUND_H_INCLUDED */

