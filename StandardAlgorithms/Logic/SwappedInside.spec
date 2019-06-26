
#ifndef SWAPPEDINSIDE_SPEC_INCLUDED
#define SWAPPEDINSIDE_SPEC_INCLUDED

#include "Unchanged.spec"

/*@
  predicate
    SwappedInside{K,L}(value_type* a, integer i, integer k, integer n) =
      0 <= i < k < n              &&
      \at(a[i],K) == \at(a[k],L)  &&
      \at(a[k],K) == \at(a[i],L)  &&
      Unchanged{K,L}(a, 0,   i)   &&
      Unchanged{K,L}(a, i+1, k)   &&
      Unchanged{K,L}(a, k+1, n);
*/

#endif /* SWAPPEDINSIDE_SPEC_INCLUDED */

