
#ifndef MULTISETRETAINREST_H_INCLUDED
#define MULTISETRETAINREST_H_INCLUDED

#include "CountLogic.h"

/*@
  predicate
    MultisetRetainRest{A,B}(value_type* a, integer m,
                            value_type* b, integer n,
                            value_type v) =
       \forall value_type x;
         x != v ==> Count{A}(a, m, x) == Count{B}(b, n, x);
*/

#endif /* MULTISETRETAINREST_H_INCLUDED */

