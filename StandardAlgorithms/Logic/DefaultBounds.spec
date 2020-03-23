
#ifndef DEFAULTBOUNDS_SPEC_INCLUDED
#define DEFAULTBOUNDS_SPEC_INCLUDED

#include "limits.h"

/*@
  axiomatic DefaultBounds
  {
    predicate
    DefaultBounds{L}(value_type* a, integer n) =
      \forall integer i; 0 <= i < n  ==>
        VALUE_TYPE_MIN <= a[i] <= VALUE_TYPE_MAX;
  }
*/

#endif /* DEFAULTBOUNDS_SPEC_INCLUDED */

