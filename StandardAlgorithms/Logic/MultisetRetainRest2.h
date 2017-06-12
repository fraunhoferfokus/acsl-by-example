
#ifndef MULTISETRETAINREST2_H_INCLUDED
#define MULTISETRETAINREST2_H_INCLUDED

#include "MultisetRetainRest.h"

/*@
  predicate
    MultisetRetainRest{K,L}(value_type* a, integer n,
                            value_type  v, value_type w) =
      \forall value_type x;
        x != v  ==>  x != w  ==>  MultisetRetain{K,L}(a, n, x);
*/

#endif /* MULTISETRETAINREST2_H_INCLUDED */

