
#ifndef COUNT2_SPEC_INCLUDED
#define COUNT2_SPEC_INCLUDED

#include "typedefs.h"

/*@
  inductive Count2{L}(value_type *a, integer n, value_type v, integer sum) {
    case Nil{L}:
      \forall value_type *a, v, integer n;
        n <= 0 ==>
          Count2{L}(a, n, v, 0);

    case Hit{L}:
      \forall value_type *a, v, integer n, sum;
        0 < n && a[n-1] == v && Count2{L}(a, n-1, v, sum) ==>
          Count2{L}(a, n, v, sum + 1);

    case Miss{L}:
      \forall value_type *a, v, integer n, sum;
        0 < n && a[n-1] != v && Count2{L}(a, n-1, v, sum) ==>
          Count2{L}(a, n, v, sum);
  }
*/

#endif /* COUNT2_SPEC_INCLUDED */

