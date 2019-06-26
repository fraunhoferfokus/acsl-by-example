
#ifndef MULTISETRETAINREST2_SPEC_INCLUDED
#define MULTISETRETAINREST2_SPEC_INCLUDED

#include "MultisetRetainRest.spec"

/*@
  predicate
    MultisetRetainRest{K,L}(value_type* a, integer n,
                            value_type  v, value_type w) =
      \forall value_type x;
        x != v  ==>  x != w  ==>  MultisetRetain{K,L}(a, n, x);
*/

#endif /* MULTISETRETAINREST2_SPEC_INCLUDED */

