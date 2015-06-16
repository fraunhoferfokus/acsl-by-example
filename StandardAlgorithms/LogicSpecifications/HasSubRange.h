#ifndef  HASSUBRANGE_H_INCLUDED
#define  HASSUBRANGE_H_INCLUDED

#include "EqualRanges.h"

/*@
  predicate
    HasSubRange{A}(value_type* a, integer m,
                   value_type* b, integer n) =
      \exists size_type k;
         (0 <= k <= m-n) && EqualRanges{A,A}(a+k, n, b);
*/

#endif /*  HASSUBRANGE_H_INCLUDED */
