
#ifndef ACCUMULATEDEFAULTBOUNDS_SPEC_INCLUDED
#define ACCUMULATEDEFAULTBOUNDS_SPEC_INCLUDED

#include "AccumulateDefault.spec"
#include "limits.h"

/*@
  predicate
    AccumulateDefaultBounds{L}(value_type* a, integer n) =
      \forall integer i; 0 <= i < n ==>
        VALUE_TYPE_MIN <= AccumulateDefault(a, i) <= VALUE_TYPE_MAX;
*/

#endif /* ACCUMULATEDEFAULTBOUNDS_SPEC_INCLUDED */

