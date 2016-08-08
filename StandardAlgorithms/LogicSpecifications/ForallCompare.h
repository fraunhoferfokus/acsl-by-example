
#ifndef FORALL_COMPARE_H_INCLUDED
#define FORALL_COMPARE_H_INCLUDED

#include "ConstantRange.h"

/*@
  predicate
    StrictLowerBound(value_type* a, integer first, integer last,  value_type v) =
      \forall integer i; first <= i < last  ==>  v <  a[i];


  predicate
    LowerBound(value_type* a, integer first, integer last, value_type v) =
      \forall integer i; first <= i < last  ==>  v <= a[i];


  predicate
    StrictUpperBound(value_type* a, integer first, integer last, value_type v) =
      \forall integer i; first <= i < last  ==>  a[i] <  v;


  predicate
    UpperBound(value_type* a, integer first, integer last, value_type v) =
      \forall integer i; first <= i < last  ==>  a[i] <= v;
*/

#endif /* FORALL_COMPARE_H_INCLUDED */

