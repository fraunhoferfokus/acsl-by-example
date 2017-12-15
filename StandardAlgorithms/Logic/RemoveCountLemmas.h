
#ifndef REMOVECOUNTLEMMAS_H_INCLUDED
#define REMOVECOUNTLEMMAS_H_INCLUDED

#include "RemoveCount.h"
#include "CountLemmas.h"
#include "CountBounds.h"
#include "CountMonotonic.h"

/*@
  lemma
    RemoveCountMonotonic:
      \forall value_type *a, v, integer m, n; 0 <= m <= n  ==>
        RemoveCount(a, m, v) <= RemoveCount(a, n, v);

  lemma
    RemoveCountStrictlyMonotonic:
      \forall value_type *a, v, integer m, n; 0 <= m < n   ==>
        a[m] != v  ==>  RemoveCount(a, m, v) < RemoveCount(a, n, v);
*/

#endif /* REMOVECOUNTLEMMAS_H_INCLUDED */

