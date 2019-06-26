
#ifndef MINELEMENT_SPEC_INCLUDED
#define MINELEMENT_SPEC_INCLUDED

#include "LowerBound.spec"

/*@
  predicate
    MinElement{L}(value_type* a, integer n, integer min) =
      0 <= min < n && LowerBound(a, n, a[min]);
*/

#endif /* MINELEMENT_SPEC_INCLUDED */

