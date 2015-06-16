
#ifndef REMOVECOUNTLEMMAS_H_INCLUDED
#define REMOVECOUNTLEMMAS_H_INCLUDED

#include "RemoveCount.h"
#include "CountLemmas.h"

/*@
  lemma RemoveCountMonotonic :
     \forall value_type *a, v, integer m, n; 0 <= m <= n ==>
        RemoveCount(a, m, v) <= RemoveCount(a, n, v);

  lemma RemoveCountStrictlyMonotonic :
     \forall value_type *a, v, integer n;
       \forall integer i; 0 <= i < n ==> a[i] != v  ==>
          RemoveCount(a, i, v) < RemoveCount(a, n, v);
*/

#endif /* REMOVECOUNTLEMMAS_H_INCLUDED */

