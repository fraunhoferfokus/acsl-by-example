
#ifndef  HASSUBRANGE_H_INCLUDED
#define  HASSUBRANGE_H_INCLUDED

#include "EqualRanges.h"

/*@
  predicate
    HasSubRange{A}(value_type* a, integer f, integer l, value_type* b, integer n) =
      \exists integer k; (f <= k <= l-n) && EqualRanges{A,A}(a+k, n, b);

  predicate
    HasSubRange{A}(value_type* a, integer m, value_type* b, integer n) =
      HasSubRange{A}(a, 0, m, b, n);

  lemma
    HasSubRangeSizes:
      \forall value_type *a, *b, integer f, t, n;
        HasSubRange(a, f, t, b, n) ==> n <= t-f;
*/

#endif /*  HASSUBRANGE_H_INCLUDED */

