
#ifndef MULTISETRETAIN_SPEC_INCLUDED
#define MULTISETRETAIN_SPEC_INCLUDED

#include "Count.spec"

/*@
  predicate
    MultisetRetain{K,L}(value_type* a, integer n, value_type v) =
      Count{K}(a, n, v) == Count{L}(a, n, v);
*/

#endif /* MULTISETRETAIN_SPEC_INCLUDED */

