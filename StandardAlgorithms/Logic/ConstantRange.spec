
#ifndef CONSTANTRANGE_SPEC_INCLUDED
#define CONSTANTRANGE_SPEC_INCLUDED

#include "typedefs.h"

/*@
  predicate
    ConstantRange(value_type* a, integer m, integer n, value_type v) =
      \forall integer i; m <= i < n ==> a[i] == v;

  predicate
    ConstantRange(value_type* a, integer m, integer n) =
      ConstantRange(a, m, n, a[m]);

  predicate
    ConstantRange(value_type* a, integer n, value_type v) =
      ConstantRange(a, 0, n, v);
*/

#endif /* CONSTANTRANGE_SPEC_INCLUDED */

