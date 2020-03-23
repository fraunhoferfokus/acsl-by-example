
#ifndef  HASCONSTANTSUBRANGE_SPEC_INCLUDED
#define  HASCONSTANTSUBRANGE_SPEC_INCLUDED

#include "AllSomeNot.spec"

/*@
  axiomatic HasConstantSubRange
  {
    predicate
    HasConstantSubRange{L}(value_type* a, integer m, integer n, value_type v, integer p) =
      \exists integer k; m <= k <= n-p && AllEqual(a, k, k+p, v);

    predicate
    HasConstantSubRange{L}(value_type* a, integer n, value_type v, integer p) =
      HasConstantSubRange(a, 0, n, v, p);

    lemma HasConstantSubRangeSizes:
      \forall value_type *a, v, integer n, p;
        HasConstantSubRange(a, n, v, p)  ==>  p <= n;
  }
*/

#endif /*  HASCONSTANTSUBRANGE_SPEC_INCLUDED */

