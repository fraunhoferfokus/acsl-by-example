
#ifndef SORTEDUPPERBOUND_H_INCLUDED
#define SORTEDUPPERBOUND_H_INCLUDED

#include "Sorted.h"
#include "UpperBound.h"

/*@
  lemma
    SortedUpperBound{L}:
      \forall value_type *a, integer n;
        UpperBound(a, n, a[n])  ==>
        Sorted(a, n)            ==>
        Sorted(a, n+1);
*/

#endif /* SORTEDUPPERBOUND_H_INCLUDED */

