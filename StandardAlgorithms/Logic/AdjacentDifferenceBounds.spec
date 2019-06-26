
#ifndef ADJACENTDIFFERENCEBOUNDS_SPEC_INCLUDED
#define ADJACENTDIFFERENCEBOUNDS_SPEC_INCLUDED

#include "AdjacentDifference.spec"
#include "limits.h"

/*@
  predicate
    AdjacentDifferenceBounds(value_type* a, integer n) =
      \forall integer i; 1 <= i < n ==>
        VALUE_TYPE_MIN <= Difference(a, i) <= VALUE_TYPE_MAX;
*/

#endif /* ADJACENTDIFFERENCEBOUNDS_SPEC_INCLUDED */

