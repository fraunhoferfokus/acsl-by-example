
#ifndef POSITIVECOUNTIMPLIESHASVALUE_SPEC_INCLUDED
#define POSITIVECOUNTIMPLIESHASVALUE_SPEC_INCLUDED

#include "HasValue.spec"
#include "CountBounds.spec"

/*@
  lemma
    PositiveCountImpliesHasValue{L}:
      \forall value_type *a, v, integer m, n;
        0 <= m < n             ==>
        Count(a, m, n, v) > 0  ==>
        HasValue(a, m, n, v);
*/

#endif /* POSITIVECOUNTIMPLIESHASVALUE_SPEC_INCLUDED */

