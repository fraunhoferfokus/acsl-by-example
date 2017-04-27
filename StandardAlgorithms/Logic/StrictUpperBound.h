
#ifndef STRICTUPPERBOUND_H_INCLUDED
#define STRICTUPPERBOUND_H_INCLUDED

#include "typedefs.h"

/*@
  predicate
    StrictUpperBound{L}(value_type* a, integer m, integer n, value_type v) =
      \forall integer i; m <= i < n  ==>  a[i] < v;

  predicate
    StrictUpperBound{L}(value_type* a, integer n, value_type v) =
      StrictUpperBound{L}(a, 0, n, v);
*/

#endif /* STRICTUPPERBOUND_H_INCLUDED */

