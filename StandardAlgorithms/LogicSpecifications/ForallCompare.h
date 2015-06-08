
#ifndef FORALL_COMPARE_H_INCLUDED
#define FORALL_COMPARE_H_INCLUDED

#include "typedefs.h"

/*@
  predicate ConstantRange(value_type* a, integer first,
                          integer last, value_type val) =
     \forall integer i; first <= i < last ==> a[i] == val;

  predicate StrictLowerBound(value_type* a, integer first,
                             integer last, value_type val) =
     \forall integer i; first <= i < last ==> val < a[i];

  predicate LowerBound(value_type* a, integer first,
                       integer last, value_type val) =
     \forall integer i; first <= i < last ==> !(a[i] < val);

  predicate StrictUpperBound(value_type* a, integer first,
                             integer last, value_type val) =
     \forall integer i; first <= i < last ==> a[i] < val;

  predicate UpperBound(value_type* a, integer first,
                       integer last, value_type val) =
     \forall integer i; first <= i < last ==> !(val < a[i]);
*/

#endif /* FORALL_COMPARE_H_INCLUDED */
