
#ifndef MULTISETRETAINREST_H_INCLUDED
#define MULTISETRETAINREST_H_INCLUDED

#include "MultisetRetain.h"

/*@
  predicate
    MultisetRetainRest{K,L}(value_type* a, integer m1, integer m2,
                            value_type* b, integer n1, integer n2,
                            value_type  v) =

       \forall value_type x;
         x != v ==> Count{K}(a, m1, m2, x) == Count{L}(b, n1, n2, x);


  predicate
    MultisetRetainRest{K,L}(value_type* a, integer m,
                            value_type* b, integer n,
                            value_type  v) =
      MultisetRetainRest{K,L}(a, 0, m, b, 0, n, v);
*/

#endif /* MULTISETRETAINREST_H_INCLUDED */

