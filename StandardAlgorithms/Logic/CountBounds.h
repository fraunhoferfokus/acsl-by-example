
#ifndef COUNTBOUNDS_H_INCLUDED
#define COUNTBOUNDS_H_INCLUDED

#include "CountLogic.h"
#include "CountSectionLemmas.h"

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

#endif /* COUNTBOUNDS_H_INCLUDED */

