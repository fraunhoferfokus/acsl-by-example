
#ifndef REMOVEMAPPING_H_INLCUDED
#define REMOVEMAPPING_H_INLCUDED

#include "RemoveCount.h"

/*@
  predicate 
    RemoveMapping{K,L}(value_type* a, integer n, value_type* b, value_type v) =
      \forall integer i; 0 <= i < n ==>
        \at(a[i],K) != v ==> \at(b[RemoveCount{K}(a, i, v)],L) == \at(a[i],K);
*/

#endif /* REMOVEMAPPING_H_INLCUDED */

