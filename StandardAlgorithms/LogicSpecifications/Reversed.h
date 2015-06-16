
#ifndef REVERSED_H_INCLUDED
#define REVERSED_H_INCLUDED

#include "typedefs.h"

/*@
    predicate 
      Reversed{A,B}(value_type* a, integer n, value_type* b,
                   integer first, integer last) =
        \forall integer k; first <= k < last 
           ==> \at(a[k], A) == \at(b[n-1-k], B);


    predicate 
      Reversed{A,B}(value_type* a, integer n, value_type* b) =
        Reversed{A,B}(a, n, b, 0, n);

*/

#endif /* REVERSED_H_INCLUDED */

