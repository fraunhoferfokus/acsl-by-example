
#ifndef HASVALUE_SPEC_INCLUDED
#define HASVALUE_SPEC_INCLUDED

#include "typedefs.h"

/*@
  predicate
    HasValue{A}(value_type* a, integer m, integer n, value_type v) =
      \exists integer i; m <= i < n && a[i] == v;

  predicate
    HasValue{A}(value_type* a, integer n, value_type v) =
      HasValue(a, 0, n, v);
*/

#endif /* HASVALUE_SPEC_INCLUDED */

