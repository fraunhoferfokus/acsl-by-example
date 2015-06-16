
#ifndef COUNTLEMMAS_H_INCLUDED
#define COUNTLEMMAS_H_INCLUDED

#include "CountAxiomatic.h"

/*@
  lemma CountOne: \forall value_type *a, v, integer n;
     Count(a, n + 1, v) == Count(a, n, v) + Count(a + n, 1, v);

  lemma CountUnion: \forall value_type *a, v, integer n, k;
     0 <= k ==>
     Count(a, n + k, v) == Count(a, n, v) + Count(a + n, k, v);

  lemma CountBounds: \forall value_type *a, v, integer n;
      0 <= n ==> 0 <= Count(a, n, v) <= n;

  lemma CountMonotonic: \forall value_type *a, v, integer m, n;
      0 <= m <= n ==> Count(a, m, v) <= Count(a, n, v);
*/

#endif /* COUNTLEMMAS_H_INCLUDED */

