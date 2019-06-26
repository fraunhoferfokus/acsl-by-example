
#ifndef STRICTLOWERBOUND_SPEC_INCLUDED
#define STRICTLOWERBOUND_SPEC_INCLUDED

#include "typedefs.h"

/*@
  predicate
    StrictLowerBound{L}(value_type* a, integer m, integer n, value_type v) =
      \forall integer i; m <= i < n  ==>  v < a[i];

  predicate
    StrictLowerBound{L}(value_type* a, integer n, value_type v) =
      StrictLowerBound{L}(a, 0, n, v);
*/

#endif /* STRICTLOWERBOUND_SPEC_INCLUDED */

