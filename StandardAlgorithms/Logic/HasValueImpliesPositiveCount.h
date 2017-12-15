
#ifndef HASVALUEIMPLIESPOSITIVECOUNT_H_INCLUDED
#define HASVALUEIMPLIESPOSITIVECOUNT_H_INCLUDED

#include "HasValue.h"
#include "CountBounds.h"

/*@
  lemma
    HasValueImpliesPositiveCount{L}:
      \forall value_type *a, v, integer m, n;
        0 <= m < n            ==>
        HasValue(a, m, n, v)  ==>
        Count(a, m, n, v) > 0;
*/

#endif /* HASVALUEIMPLIESPOSITIVECOUNT_H_INCLUDED */

