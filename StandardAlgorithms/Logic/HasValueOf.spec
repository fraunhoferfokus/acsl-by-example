
#ifndef HASVALUEOF_SPEC_INCLUDED
#define HASVALUEOF_SPEC_INCLUDED

#include "SomeNone.spec"

/*@
  axiomatic HasValueOf
  {
    predicate
    HasValueOf{A}(value_type* a, integer m, value_type* b, integer n) =
      \exists integer i; 0 <= i < m && SomeEqual{A}(b, n, a[i]);
  }
*/

#endif /* HASVALUEOF_SPEC_INCLUDED */

