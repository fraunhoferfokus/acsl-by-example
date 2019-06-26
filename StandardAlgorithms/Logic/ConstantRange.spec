
#ifndef CONSTANTRANGE_SPEC_INCLUDED
#define CONSTANTRANGE_SPEC_INCLUDED

#include "typedefs.h"

/*@
  predicate
    ConstantRange(value_type* a, integer first, integer last, value_type v) =
      \forall integer i; first <= i < last ==> a[i] == v;

  predicate
    ConstantRange(value_type* a, integer first, integer last) =
      ConstantRange(a, first, last, a[first]);

  predicate
    ConstantRange(value_type* a, integer n, value_type v) =
      ConstantRange(a, 0, n, v);
*/

#endif /* CONSTANTRANGE_SPEC_INCLUDED */

