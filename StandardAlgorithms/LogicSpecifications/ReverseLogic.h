
#ifndef REVERSELOGIC_H_INCLUDED
#define REVERSELOGIC_H_INCLUDED

#include "typedefs.h"

/*@
  predicate 
    Reverse{A,B}(value_type* a, integer n, value_type* b, integer l, integer r) =
      \forall integer k; l <= k < r ==> \at(a[k], A) == \at(b[n-1-k], B);

  predicate 
    Reverse{A,B}(value_type* a, integer n, value_type* b) =
      Reverse{A,B}(a, n, b, 0, n);

  predicate 
    Reverse{A,B}(value_type* a, integer n) = Reverse{A,B}(a, n, a);

*/

#endif /* REVERSELOGIC_H_INCLUDED */

