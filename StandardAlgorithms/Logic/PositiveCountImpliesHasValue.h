
#ifndef POSITIVECOUNTIMPLIESHASVALUE_H_INCLUDED
#define POSITIVECOUNTIMPLIESHASVALUE_H_INCLUDED

#include "HasValue.h"
#include "CountBounds.h"

/*@
  lemma
    PositiveCountImpliesHasValue{L}:
      \forall value_type *a, v, integer m, n;
        0 <= m < n             ==>
        Count(a, m, n, v) > 0  ==>
        HasValue(a, m, n, v);
*/

#endif /* POSITIVECOUNTIMPLIESHASVALUE_H_INCLUDED */

