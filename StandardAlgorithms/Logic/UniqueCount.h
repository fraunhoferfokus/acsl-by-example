#ifndef UNIQUECOUNT_H_INCLUDED
#define UNIQUECOUNT_H_INCLUDED

#include "CountAdjacent.h"

/*@
  logic integer
    UniqueCount{L}(value_type* a, integer n) = n - CountAdjacent{L}(a, n+1);

  lemma UniqueCountEmpty:
    \forall value_type *a, integer n;
      n <= 1  ==>  UniqueCount(a, n) == n;
    
  lemma UniqueCountEqual:
    \forall value_type *a, integer n;
      n > 1  ==>  a[n-1] == a[n] ==> UniqueCount(a, n+1) == UniqueCount(a, n);
    
  lemma UniqueCountDifferent:
    \forall value_type *a, integer n;
      n > 1  ==>  a[n-1] != a[n] ==> UniqueCount(a, n+1) == UniqueCount(a, n) + 1;
    
*/

#endif /* UNIQUECOUNT_H_INCLUDED */

