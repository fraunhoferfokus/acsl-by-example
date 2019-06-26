
#ifndef HASVALUEOF_SPEC_INCLUDED
#define HASVALUEOF_SPEC_INCLUDED

#include "HasValue.spec"

/*@
  predicate
    HasValueOf{A}(value_type* a, integer m, value_type* b, integer n) =
      \exists integer i; 0 <= i < m && HasValue{A}(b, n, a[i]);
*/

#endif /* HASVALUEOF_SPEC_INCLUDED */

