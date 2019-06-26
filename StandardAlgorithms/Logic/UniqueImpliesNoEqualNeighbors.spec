
#ifndef UNIQUEIMPLIESNOEQUALNEIGHBORS_SPEC_INCLUDED
#define UNIQUEIMPLIESNOEQUALNEIGHBORS_SPEC_INCLUDED

#include "Unique.spec"
#include "HasEqualNeighbors.spec"

/*@
  lemma UniqueImpliesNoEqualNeighbors:
    \forall value_type *a, *b, integer n;
       Unique(a, n, b)  ==>  !HasEqualNeighbors(b, UniqueSize(a, n));
*/

#endif /* UNIQUEIMPLIESNOEQUALNEIGHBORS_SPEC_INCLUDED */

