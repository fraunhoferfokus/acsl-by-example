
#ifndef EQUALRANGES_H_INCLUDED
#define EQUALRANGES_H_INCLUDED

#include "typedefs.h"

/*@
  predicate
    EqualRanges{A,B}(value_type* a, integer m, integer n, value_type* b) =
      \forall integer i; m <= i < n ==> \at(a[i], A) == \at(b[i], B);

  predicate
    EqualRanges{A,B}(value_type* a, integer n, value_type* b) =
      EqualRanges{A,B}(a, 0, n, b);
*/

#endif /* EQUALRANGES_H_INCLUDED */

