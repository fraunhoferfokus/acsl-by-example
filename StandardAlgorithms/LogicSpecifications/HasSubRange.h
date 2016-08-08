
#ifndef  HASSUBRANGE_H_INCLUDED
#define  HASSUBRANGE_H_INCLUDED

#include "EqualRanges.h"

/*@
  predicate
    HasSubRange{A}(value_type* a, integer m, value_type* b, integer n) =
      \exists integer k; (0 <= k <= m-n) && EqualRanges{A,A}(a+k, n, b);
*/

/*@
  lemma HasSubRange_fit_size:
    \forall value_type* a, integer m, value_type* b, integer n;
      HasSubRange(a, m, b, n) ==> n <= m;
*/

#endif /*  HASSUBRANGE_H_INCLUDED */

