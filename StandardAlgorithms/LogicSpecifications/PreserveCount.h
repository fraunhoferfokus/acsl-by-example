
#ifndef PRESERVECOUNT_H_INCLUDED
#define PRESERVECOUNT_H_INCLUDED

#include "CountAxiomatic.h"

/*@
  predicate
    PreserveCount(value_type* a, size_type m, 
                  value_type* b, size_type n, value_type v) =
       \forall value_type x; x != v ==>
          Count(a, m, x) == Count(b, n, x);
*/

#endif /* PRESERVECOUNT_H_INCLUDED */

