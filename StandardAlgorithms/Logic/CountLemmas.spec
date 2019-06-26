
#ifndef COUNTLEMMAS_SPEC_INCLUDED
#define COUNTLEMMAS_SPEC_INCLUDED

#include "Count.spec"
#include "CountSectionLemmas.spec"

/*@
  lemma
    CountOne:
      \forall value_type *a, v, integer n;
        0 <= n ==>
          Count(a, n+1, v) == Count(a, n, v) + Count(a, n, n+1, v);

  lemma
    CountUnion:
      \forall value_type *a, v, integer m, n;
        0 <= m <= n  ==>
        Count(a, n, v) == Count(a, 0, m, v) + Count(a, m, n, v);
*/

#endif /* COUNTLEMMAS_SPEC_INCLUDED */

