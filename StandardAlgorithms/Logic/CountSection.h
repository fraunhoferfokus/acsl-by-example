
#ifndef COUNTSECTION_H_INCLUDED
#define COUNTSECTION_H_INCLUDED

#include "Unchanged.h"

/*@
  axiomatic Count
  {
    logic integer
    Count{L}(value_type* a, integer m, integer n, value_type v) reads a[m..n-1];

    axiom
      CountSectionEmpty{L}:
        \forall value_type *a, v, integer m, n;
          n <= m  ==>  Count(a, m, n, v) == 0;

    axiom
      CountSectionHit{L}:
        \forall value_type *a, v, integer n, m;
          m < n  ==> a[n-1] == v  ==>  Count(a, m, n, v) == Count(a, m, n-1, v) + 1;

    axiom
      CountSectionMiss{L}:
        \forall value_type *a, v, integer n, m;
          m < n  ==> a[n-1] != v  ==>  Count(a, m, n, v) == Count(a, m, n-1, v);

    axiom
      CountSectionRead{K,L}:
        \forall value_type *a, v, integer m, n;
          Unchanged{K,L}(a, m, n)  ==>
            Count{K}(a, m, n, v) == Count{L}(a, m, n, v);
  }
*/

#endif /* COUNTSECTION_H_INCLUDED */
