
#ifndef MULTISETMINUS_SPEC_INCLUDED
#define MULTISETMINUS_SPEC_INCLUDED

#include "Count.spec"

/*@
  predicate
    MultisetMinus{K,L}(value_type* a, integer n, value_type val) =
      Count{L}(a, n, val) == Count{K}(a, n, val) - 1;
*/

#endif /* MULTISETMINUS_SPEC_INCLUDED */

