
#ifndef WEAKLYSORTED_SPEC_INCLUDED
#define WEAKLYSORTED_SPEC_INCLUDED

#include "typedefs.h"

/*@
  predicate
    WeaklySorted{L}(value_type* a, integer m, integer n) =
      \forall integer i; m <= i < n-1 ==> a[i] <= a[i+1];

  predicate
    WeaklySorted{L}(value_type* a, integer n) = WeaklySorted{L}(a, 0, n);
*/

#endif /* WEAKLYSORTED_SPEC_INCLUDED */

