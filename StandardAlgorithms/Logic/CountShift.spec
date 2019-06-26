
#ifndef COUNTSHIFT_SPEC_INCLUDED
#define COUNTSHIFT_SPEC_INCLUDED

#include "CountSectionLemmas.spec"

/*@
  lemma
    CountShift{L}:
      \forall value_type *a, v, integer m, n;
        0 <= m  ==>  0 <= n  ==>
        Count(a+m, 0, n, v) == Count(a, m, m+n, v);
*/

#endif /* COUNTSHIFT_SPEC_INCLUDED */

