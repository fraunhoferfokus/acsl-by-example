
#ifndef UNIQUE_IMPLIES_NO_EQUAL_NEIGHBORS_H_INCLUDED
#define UNIQUE_IMPLIES_NO_EQUAL_NEIGHBORS_H_INCLUDED

#include "Unique.h"
#include "HasEqualNeighbors.h"

/*@
  lemma UniqueImpliesNoEqualNeighbors:
    \forall value_type *a, *b, integer n;
       Unique(a, n, b)  ==>  !HasEqualNeighbors(b, UniqueSize(a, n));
*/

#endif /* UNIQUE_IMPLIES_NO_EQUAL_NEIGHBORS_H_INCLUDED */

