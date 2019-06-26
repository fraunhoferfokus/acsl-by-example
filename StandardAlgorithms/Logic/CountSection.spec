
#ifndef COUNTSECTION_SPEC_INCLUDED
#define COUNTSECTION_SPEC_INCLUDED

#include "Unchanged.spec"

/*@
  axiomatic CountAxiomatic
  {
    logic integer
    Count{L}(value_type* a, integer m, integer n, value_type v) =
      n <= m ? 0 : Count(a, m, n-1, v) + (a[n-1] == v ? 1 : 0);

    lemma
      CountSectionEmpty{L}:
        \forall value_type *a, v, integer m, n;
          n <= m  ==>  Count(a, m, n, v) == 0;

    lemma
      CountSectionHit{L}:
        \forall value_type *a, v, integer n, m;
          m < n  ==> a[n-1] == v  ==>  Count(a, m, n, v) == Count(a, m, n-1, v) + 1;

    lemma
      CountSectionMiss{L}:
        \forall value_type *a, v, integer n, m;
          m < n  ==> a[n-1] != v  ==>  Count(a, m, n, v) == Count(a, m, n-1, v);

    lemma
      CountSectionRead{K,L}:
        \forall value_type *a, v, integer m, n;
          Unchanged{K,L}(a, m, n)  ==>
            Count{K}(a, m, n, v) == Count{L}(a, m, n, v);
  }
*/

#endif /* COUNTSECTION_SPEC_INCLUDED */
