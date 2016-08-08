
#ifndef MINELEMENT_H_INCLUDED
#define MINELEMENT_H_INCLUDED

#include "ForallCompare.h"

/*@
  predicate
    MinElement{L}(value_type* a, integer n, integer min) =
      0 <= min < n && LowerBound(a, 0, n, a[min]);
*/

#endif /* MINELEMENT_H_INCLUDED */

