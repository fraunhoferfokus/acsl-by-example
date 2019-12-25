
#ifndef ACCUMULATEBOUNDS_SPEC_INCLUDED
#define ACCUMULATEBOUNDS_SPEC_INCLUDED

#include "Accumulate.spec"
#include "limits.h"

/*@
  predicate
    AccumulateBounds{L}(value_type* a, integer n, value_type init) =
      \forall integer i; 0 <= i <= n ==>
        VALUE_TYPE_MIN <= Accumulate(a, i, init) <= VALUE_TYPE_MAX;
*/

#endif /* ACCUMULATEBOUNDS_SPEC_INCLUDED */

