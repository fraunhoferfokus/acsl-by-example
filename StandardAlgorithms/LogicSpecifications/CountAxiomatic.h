
#ifndef COUNTAXIOMATIC_H_INCLUDED
#define COUNTAXIOMATIC_H_INCLUDED

#include "EqualRanges.h"

/*@
  axiomatic CountAxiomatic
  {
    logic integer Count{L}(value_type* a, integer n, value_type v)
        reads a[0..n-1];

    axiom CountEmpty: \forall value_type *a, v, integer n;
        n <= 0 ==> Count(a, n, v) == 0;

    axiom CountOneHit: \forall value_type *a, v, integer n;
        (a[n] == v ==> Count(a, n + 1, v) == Count(a, n, v) + 1);

    axiom CountOneMiss: \forall value_type *a, v, integer n;
        (a[n] != v ==> Count(a, n + 1, v) == Count(a, n, v));

    axiom CountRead{L1,L2}: \forall value_type *a, v, integer n;
        EqualRanges{L1,L2}(a, n) ==>
             Count{L1}(a, n, v) == Count{L2}(a, n, v);
  }
*/

#endif /* COUNTAXIOMATIC_H_INCLUDED */
