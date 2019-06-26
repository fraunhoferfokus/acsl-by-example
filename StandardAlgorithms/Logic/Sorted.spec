
#ifndef SORTED_SPEC_INCLUDED
#define SORTED_SPEC_INCLUDED

#include "typedefs.h"

/*@
  predicate
    Sorted{L}(value_type* a, integer m, integer n) =
      \forall integer i, j; m <= i < j < n ==> a[i] <= a[j];

  predicate
    Sorted{L}(value_type* a, integer n) = Sorted{L}(a, 0, n);
*/

#endif /* SORTED_SPEC_INCLUDED */

