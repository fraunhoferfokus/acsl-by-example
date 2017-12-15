
#ifndef COUNTSHIFT_H_INCLUDED
#define COUNTSHIFT_H_INCLUDED

#include "CountSectionLemmas.h"

/*@
  lemma
    CountShift{L}:
      \forall value_type *a, v, integer m, n;
        0 <= m  ==>  0 <= n  ==>
        Count(a+m, 0, n, v) == Count(a, m, m+n, v);
*/

#endif /* COUNTSHIFT_H_INCLUDED */

