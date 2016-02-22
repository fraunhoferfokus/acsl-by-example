
#ifndef EQUALRANGES_H_INCLUDED
#define EQUALRANGES_H_INCLUDED

#include "typedefs.h"

/*@
  predicate
    EqualRanges{A,B}(value_type* a, integer n, value_type* b) =
      \forall integer i; 0 <= i < n ==> \at(a[i], A) == \at(b[i], B);
*/

#endif /* EQUALRANGES_H_INCLUDED */

