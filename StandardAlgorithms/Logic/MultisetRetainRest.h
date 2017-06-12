
#ifndef MULTISETRETAINREST_H_INCLUDED
#define MULTISETRETAINREST_H_INCLUDED

#include "MultisetRetain.h"

/*@
  predicate
    MultisetRetainRest{K,L}(value_type* a, integer m,
                            value_type* b, integer n,
                            value_type  v) =

       \forall value_type x;
         x != v ==> Count{K}(a, m, x) == Count{L}(b, n, x);
*/

#endif /* MULTISETRETAINREST_H_INCLUDED */

