
#ifndef CONSTANT_RANGE_H_INCLUDED
#define CONSTANT_RANGE_H_INCLUDED

#include "typedefs.h"

/*@
  predicate
    ConstantRange(value_type* a, integer first, integer last, value_type val) =
      \forall integer i; first <= i < last ==> a[i] == val;
*/

#endif /* CONSTANT_RANGE_H_INCLUDED */

