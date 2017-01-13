
#ifndef EQUALRANGES_H_INCLUDED
#define EQUALRANGES_H_INCLUDED

#include "typedefs.h"

/*@
  predicate
    EqualRanges{K,L}(value_type* a, integer m, integer n,
                     value_type* b, integer p) =
      \let s = n - m;
      \forall integer i; 0 <= i < s ==> \at(a[m+i],K) == \at(b[p+i],L);

  predicate
    EqualRanges{K,L}(value_type* a, integer m, integer n, integer p) =
      EqualRanges{K,L}(a, m, n, a, p);

  predicate
    EqualRanges{K,L}(value_type* a, integer m, integer n, value_type* b) =
      \forall integer i; m <= i < n ==> \at(a[i],K) == \at(b[i],L);

  predicate
    EqualRanges{K,L}(value_type* a, integer n, value_type* b) =
      EqualRanges{K,L}(a, 0, n, b);
*/

#endif /* EQUALRANGES_H_INCLUDED */

