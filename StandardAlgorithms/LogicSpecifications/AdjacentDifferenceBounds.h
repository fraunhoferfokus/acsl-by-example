
#ifndef ADJACENTIFFERENCEBOUNDS_H_INCLUDED
#define ADJACENTIFFERENCEBOUNDS_H_INCLUDED

#include "AdjacentDifference.h"
#include "limits.h"

/*@
  predicate
    AdjacentDifferenceBounds(value_type* a, integer n) =
      \forall integer i; 1 <= i < n ==>
        VALUE_TYPE_MIN <= Difference(a, i) <= VALUE_TYPE_MAX;
*/

#endif /* ADJACENTIFFERENCEBOUNDS_H_INCLUDED */

