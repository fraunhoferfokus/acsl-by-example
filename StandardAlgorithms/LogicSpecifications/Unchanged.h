
#ifndef UNCHANGED_H_INCLUDED
#define UNCHANGED_H_INCLUDED

#include "typedefs.h"

/*@
  predicate 
    Unchanged{K,L}(value_type* a, integer first, integer last) =
      \forall integer i; first <= i < last ==> \at(a[i],K) == \at(a[i],L);

  predicate
    Unchanged{K,L}(value_type* a, integer n) = Unchanged{K,L}(a, 0, n);
*/
#endif /* UNCHANGED_H_INCLUDED */

