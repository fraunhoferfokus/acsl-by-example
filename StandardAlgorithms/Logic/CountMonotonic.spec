
#ifndef COUNTMONOTONIC_SPEC_INCLUDED
#define COUNTMONOTONIC_SPEC_INCLUDED

#include "Count.spec"
#include "CountSectionLemmas.spec"

/*@
  lemma
    CountSectionMonotonic:
      \forall value_type *a, v, integer m, n, p;
        m <= n <= p ==>
          Count(a, m, n, v) <= Count(a, m, p, v);

  lemma
    CountMonotonic:
      \forall value_type *a, v, integer m, n;
        0 <= m <= n  ==>
          Count(a, m, v) <= Count(a, n, v);
*/

#endif /* COUNTMONOTONIC_SPEC_INCLUDED */

