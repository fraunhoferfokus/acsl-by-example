
#ifndef COUNTBOUNDS_SPEC_INCLUDED
#define COUNTBOUNDS_SPEC_INCLUDED

#include "Count.spec"
#include "CountSectionLemmas.spec"

/*@
  lemma
    CountSectionBounds:
      \forall value_type *a, v, integer m, n;
        0 <= m <= n ==> 0 <= Count(a, m, n, v) <= n-m;

  lemma
    CountBounds:
      \forall value_type *a, v, integer n;
        0 <= n  ==>  0 <= Count(a, n, v) <= n;
*/

#endif /* COUNTBOUNDS_SPEC_INCLUDED */

