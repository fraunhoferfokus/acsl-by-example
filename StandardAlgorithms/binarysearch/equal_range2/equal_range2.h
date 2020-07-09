
#ifndef EQUAL_RANGE_H_INCLUDED
#define EQUAL_RANGE_H_INCLUDED

#include "SizeTypePairTrivial.acsl"
#include "Increasing.acsl"
#include "AllSomeNot.acsl"
#include "ArrayBounds.acsl"

/*@
  requires valid:      \valid_read(a + (0..n-1));
  requires increasing: Increasing(a, n);
  assigns              \nothing;
  ensures result:      0 <= \result.first <= \result.second <= n;
  ensures left:        StrictUpperBound(a, 0, \result.first, v);
  ensures middle:      AllEqual(a, \result.first, \result.second, v);
  ensures right:       StrictLowerBound(a, \result.second, n, v);
 */
size_type_pair
equal_range2(const value_type* a, size_type n, value_type v);

#endif /* EQUAL_RANGE_H_INCLUDED */

