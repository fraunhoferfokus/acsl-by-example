
#ifndef COUNTLOGIC_H_INCLUDED
#define COUNTLOGIC_H_INCLUDED

#include "CountSection.h"

/*@
  logic integer
    Count{L}(value_type* a, integer n, value_type v) = Count{L}(a, 0, n, v);


  lemma CountEmpty:
    \forall value_type *a, v, integer n;
      n <= 0  ==>  Count(a, n, v) == 0;

  lemma CountOneHit:
    \forall value_type *a, v, integer n;
      a[n] == v  ==>  Count(a, n + 1, v) == Count(a, n, v) + 1;

  lemma CountOneMiss:
    \forall value_type *a, v, integer n;
      a[n] != v  ==>  Count(a, n + 1, v) == Count(a, n, v);

  lemma CountRead{L1,L2}:
    \forall value_type *a, v, integer n;
      Unchanged{L1,L2}(a, n)  ==>  Count{L1}(a, n, v) == Count{L2}(a, n, v);
*/

#endif /* COUNTLOGIC_H_INCLUDED */

