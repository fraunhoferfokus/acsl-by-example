
#ifndef  HASCONSTANTSUBRANGE_H_INCLUDED
#define  HASCONSTANTSUBRANGE_H_INCLUDED

#include "ConstantRange.h"

/*@
  predicate
    HasConstantSubRange{A}(value_type* a, integer m, integer n, value_type b) =
      \exists integer i; 0 <= i <= m-n && ConstantRange(a, i, i+n, b);
*/

/*@
  lemma HasConstantSubRange_fit_size:
    \forall value_type* a, integer m, integer n, value_type b;
      HasConstantSubRange(a, m, n, b) ==> n <= m;
*/

#endif /*  HASCONSTANTSUBRANGE_H_INCLUDED */

