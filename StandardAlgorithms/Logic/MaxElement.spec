
#ifndef MAXELEMENT_SPEC_INCLUDED
#define MAXELEMENT_SPEC_INCLUDED

#include "UpperBound.spec"

/*@
  predicate
    MaxElement{L}(value_type* a, integer n, integer max) =
      0 <= max < n && UpperBound(a, n, a[max]);
*/

#endif /* MAXELEMENT_SPEC_INCLUDED */

