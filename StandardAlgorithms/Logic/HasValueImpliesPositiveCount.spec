
#ifndef HASVALUEIMPLIESPOSITIVECOUNT_SPEC_INCLUDED
#define HASVALUEIMPLIESPOSITIVECOUNT_SPEC_INCLUDED

#include "HasValue.spec"
#include "CountBounds.spec"

/*@
  lemma
    HasValueImpliesPositiveCount{L}:
      \forall value_type *a, v, integer m, n;
        0 <= m < n            ==>
        HasValue(a, m, n, v)  ==>
        Count(a, m, n, v) > 0;
*/

#endif /* HASVALUEIMPLIESPOSITIVECOUNT_SPEC_INCLUDED */

