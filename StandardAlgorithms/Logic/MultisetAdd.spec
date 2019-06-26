
#ifndef MULTISETADD_SPEC_INCLUDED
#define MULTISETADD_SPEC_INCLUDED

#include "Count.spec"

/*@
  predicate
    MultisetAdd{K,L}(value_type* a, integer n, value_type val) =
      Count{L}(a, n, val) == Count{K}(a, n, val) + 1;
*/

#endif /* MULTISETADD_SPEC_INCLUDED */

