
#ifndef COUNTLEMMAS_H_INCLUDED
#define COUNTLEMMAS_H_INCLUDED

#include "CountLogic.h"
#include "CountSectionLemmas.h"

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

#endif /* COUNTLEMMAS_H_INCLUDED */

