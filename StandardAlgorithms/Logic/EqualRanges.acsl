
#ifndef EQUALRANGES_SPEC_INCLUDED
#define EQUALRANGES_SPEC_INCLUDED

#include "typedefs.h"

/*@
  axiomatic EqualRanges
  {
    predicate
    EqualRanges{K,L}(value_type* a, integer n, value_type* b) =
      \forall integer i; 0 <= i < n  ==>  \at(a[i],K) == \at(b[i],L);

    predicate
    EqualRanges{K,L}(value_type* a, integer m, integer n, value_type* b) =
      \forall integer i; m <= i < n  ==>  \at(a[i],K) == \at(b[i],L);

    predicate
    EqualRanges{K,L}(value_type* a, integer m, integer n,
                     value_type* b, integer p) = EqualRanges{K,L}(a+m, n-m, b+p);

    predicate
    EqualRanges{K,L}(value_type* a, integer m, integer n, integer p) =
      EqualRanges{K,L}(a, m, n, a, p);
  }
*/

#endif /* EQUALRANGES_SPEC_INCLUDED */

