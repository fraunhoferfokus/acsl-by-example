
#ifndef  HASCONSTANTSUBRANGE_SPEC_INCLUDED
#define  HASCONSTANTSUBRANGE_SPEC_INCLUDED

#include "ConstantRange.spec"

/*@
  predicate
    HasConstantSubRange{A}(value_type* a, integer m, integer n, value_type b) =
      \exists integer i; 0 <= i <= m-n && ConstantRange(a, i, i+n, b);


  lemma
    HasConstantSubRangeSizes:
      \forall value_type *a, v, integer m, n;
        HasConstantSubRange(a, m, n, v) ==> n <= m;
*/

#endif /*  HASCONSTANTSUBRANGE_SPEC_INCLUDED */

