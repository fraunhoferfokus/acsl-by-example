
#ifndef UPPERBOUND_H_INCLUDED
#define UPPERBOUND_H_INCLUDED

#include "typedefs.h"

/*@
  predicate
    UpperBound{L}(value_type* a, integer m, integer n, value_type v) =
      \forall integer i; m <= i < n  ==>  a[i] <= v;

  predicate
    UpperBound{L}(value_type* a, integer n, value_type v) =
      UpperBound{L}(a, 0, n, v);
*/

#endif /* UPPERBOUND_H_INCLUDED */

