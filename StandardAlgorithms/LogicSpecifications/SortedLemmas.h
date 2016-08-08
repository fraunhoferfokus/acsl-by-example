
#ifndef SORTEDLEMMAS_H_INCLUDED
#define SORTEDLEMMAS_H_INCLUDED

#include "Sorted.h"
#include "ForallCompare.h"

/*@
  lemma SortedUp{L}:
    \forall value_type *a, integer n;
      Sorted(a, n)               ==>
      UpperBound(a, 0, n, a[n])  ==>
      Sorted(a, n+1);
*/

#endif /* SORTEDLEMMAS_H_INCLUDED */

