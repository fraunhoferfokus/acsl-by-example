
#ifndef CONSTANT_RANGE_H_INCLUDED
#define CONSTANT_RANGE_H_INCLUDED

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

#endif /* CONSTANT_RANGE_H_INCLUDED */

