
#ifndef COUNTSECTION_H_INCLUDED
#define COUNTSECTION_H_INCLUDED

#include "Unchanged.h"

/*@
  axiomatic CountSectionLogic
  {
    logic integer
      CountSection{L}(value_type* a, integer m, integer n, value_type v)
        reads a[m..n-1];

    axiom CountSectionEmpty:
      \forall value_type *a, v, integer m, n;
        n <= m ==> CountSection(a, m, n, v) == 0;

    axiom CountSectionHit:
      \forall value_type *a, v, integer n, m;
        a[n] == v ==> CountSection(a, m, n + 1, v) == CountSection(a, m, n, v) + 1;

    axiom CountSectionMiss:
      \forall value_type *a, v, integer n, m;
        a[n] != v ==> CountSection(a, m, n + 1, v) == CountSection(a, m, n, v);

    axiom CountSectionRead{L1,L2}:
      \forall value_type *a, v, integer m, n;
        Unchanged{L1,L2}(a, m, n) ==>
          CountSection{L1}(a, m, n, v) == CountSection{L2}(a, m, n, v);
  }
*/

#endif /* COUNTSECTION_H_INCLUDED */
