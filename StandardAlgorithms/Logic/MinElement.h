
#ifndef MINELEMENT_H_INCLUDED
#define MINELEMENT_H_INCLUDED

#include "LowerBound.h"

/*@
  predicate
    MinElement{L}(value_type* a, integer n, integer min) =
      0 <= min < n && LowerBound(a, n, a[min]);
*/

#endif /* MINELEMENT_H_INCLUDED */

