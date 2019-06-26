
#ifndef COUNTSECTIONLEMMAS_SPEC_INCLUDED
#define COUNTSECTIONLEMMAS_SPEC_INCLUDED

#include "CountSection.spec"

/*@
  lemma
    CountSectionOne:
      \forall value_type *a, v, integer m, n;
        m <= n  ==>
          Count(a, m, n+1, v) == Count(a, m, n, v) + Count(a, n, n+1, v);


  lemma
    CountSectionUnion:
      \forall value_type *a, v, integer k, m, n;
        0 <= k <= m <= n  ==>
          Count(a, k, n, v) == Count(a, k, m, v) + Count(a, m, n, v);
*/

#endif /* COUNTSECTIONLEMMAS_SPEC_INCLUDED */

