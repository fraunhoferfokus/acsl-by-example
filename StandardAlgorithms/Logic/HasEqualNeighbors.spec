
#ifndef HASEQUALNEIGHBORS_SPEC_INCLUDED
#define HASEQUALNEIGHBORS_SPEC_INCLUDED

#include "typedefs.h"

/*@
  axiomatic HasEqualNeighbors
  {
    predicate
    HasEqualNeighbors{L}(value_type* a, integer n) =
      \exists integer i; 0 <= i < n-1 && a[i] == a[i+1];
  }
*/

#endif /* HASEQUALNEIGHBORS_SPEC_INCLUDED */

