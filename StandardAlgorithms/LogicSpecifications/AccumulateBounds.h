
#ifndef ACCUMULATEBOUNDS_H_INCLUDED
#define ACCUMULATEBOUNDS_H_INCLUDED

#include "AccumulateAxiomatic.h"
#include "limits.h"

/*@
  predicate
    AccumulateBounds{L}(value_type* a, integer n, value_type init) =
      \forall integer i; 0 <= i <= n ==>
        VALUE_TYPE_MIN <= Accumulate(a, i, init) <= VALUE_TYPE_MAX;

  predicate
    AccumulateBounds{L}(value_type* a, integer n) =
      AccumulateBounds{L}(a, n, (value_type) 0);
*/

#endif /* ACCUMULATEBOUNDS_H_INCLUDED */

