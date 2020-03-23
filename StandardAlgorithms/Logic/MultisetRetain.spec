
#ifndef MULTISETRETAIN_SPEC_INCLUDED
#define MULTISETRETAIN_SPEC_INCLUDED

#include "Count.spec"

/*@
  axiomatic MultisetRetain
  {
    predicate
    MultisetRetain{K,L}(value_type* a, integer n, value_type v) =
      Count{K}(a, n, v) == Count{L}(a, n, v);

    predicate
    MultisetRetainRest{K,L}(value_type* a, integer m1, integer m2,
                            value_type* b, integer n1, integer n2, value_type  v) =
      \forall value_type x;
        x != v  ==>  Count{K}(a, m1, m2, x) == Count{L}(b, n1, n2, x);

    predicate
    MultisetRetainRest{K,L}(value_type* a, integer m,
                            value_type* b, integer n, value_type  v) =
      MultisetRetainRest{K,L}(a, 0, m, b, 0, n, v);

    predicate
    MultisetRetainRest{K,L}(value_type* a, integer n, value_type  v, value_type w) =
      \forall value_type x;
        x != v  ==>  x != w  ==>  MultisetRetain{K,L}(a, n, x);
  }
*/

#endif /* MULTISETRETAIN_SPEC_INCLUDED */

