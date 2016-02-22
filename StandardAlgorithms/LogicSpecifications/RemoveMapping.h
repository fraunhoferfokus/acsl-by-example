
#ifndef REMOVEMAPPING_H_INLCUDED
#define REMOVEMAPPING_H_INLCUDED

#include "RemoveCount.h"

/*@
  predicate 
    RemoveMapping{L}(value_type* a, integer n, value_type* b, value_type v) =
      \forall integer i; 0 <= i < n ==>
        a[i] != v ==> b[RemoveCount(a, i, v)] == a[i];
*/

#endif /* REMOVEMAPPING_H_INLCUDED */

