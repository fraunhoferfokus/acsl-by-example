
#ifndef RETAINALLBUTONE_H_INCLUDED
#define RETAINALLBUTONE_H_INCLUDED

#include "CountLogic.h"

/*@
  predicate
    RetainAllButOne(value_type* a, integer m, 
                    value_type* b, integer n, value_type v) =
       \forall value_type x;
          x != v ==> Count(a, m, x) == Count(b, n, x);
*/

#endif /* RETAINALLBUTONE_H_INCLUDED */

