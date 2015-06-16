
#ifndef STABELREMOVE_H_INLCUDED
#define STABELREMOVE_H_INLCUDED

#include "RemoveCount.h"

/*@
  predicate 
    StableRemove(value_type* a, integer n, 
                 value_type* b, value_type v) =
          \forall integer i; 0 <= i < n ==>
             a[i] != v ==> b[RemoveCount(a, i, v)] == a[i];
*/

#endif /* STABELREMOVE_H_INLCUDED */

