
#ifndef LOWERBOUND_H_INCLUDED
#define LOWERBOUND_H_INCLUDED

#include "typedefs.h"

/*@
  predicate
    LowerBound{L}(value_type* a, integer m, integer n, value_type v) =
      \forall integer i; m <= i < n  ==>  v <= a[i];

  predicate
    LowerBound{L}(value_type* a, integer n, value_type v) =
      LowerBound{L}(a, 0, n, v);
*/

#endif /* LOWERBOUND_H_INCLUDED */

