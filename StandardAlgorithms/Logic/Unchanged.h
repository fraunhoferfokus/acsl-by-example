
#ifndef UNCHANGED_H_INCLUDED
#define UNCHANGED_H_INCLUDED

#include "EqualRanges.h"

/*@
  predicate 
    Unchanged{K,L}(value_type* a, integer m, integer n) =
      \forall integer i; m <= i < n ==> \at(a[i],K) == \at(a[i],L);

  predicate
    Unchanged{K,L}(value_type* a, integer n) = 
      Unchanged{K,L}(a, 0, n);
*/

#endif /* UNCHANGED_H_INCLUDED */

