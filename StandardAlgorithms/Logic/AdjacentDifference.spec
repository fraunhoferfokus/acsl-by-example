
#ifndef ADJACENTDIFFERENCE_SPEC_INCLUDED
#define ADJACENTDIFFERENCE_SPEC_INCLUDED

#include "Difference.spec"

/*@
  predicate
    AdjacentDifference{L}(value_type* a, integer n, value_type* b) =
      \forall integer i; 0 <= i < n ==> b[i] == Difference(a, i);
*/

#endif /* ADJACENTDIFFERENCE_SPEC_INCLUDED */

