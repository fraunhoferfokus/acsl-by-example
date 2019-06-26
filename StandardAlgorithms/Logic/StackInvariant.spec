
#ifndef STACKINVARIANT_SPEC_INCLUDED
#define STACKINVARIANT_SPEC_INCLUDED

#include "StackCapacitySizeTop.spec"

/*@
  predicate
    Invariant{L}(Stack* s) =
      0 < Capacity(s) &&
      0 <= Size(s) <= Capacity(s) &&
      \valid(Storage(s) + (0..Capacity(s)-1)) &&
      \separated(s, Storage(s) + (0..Capacity(s)-1));
*/

#endif /* STACKINVARIANT_SPEC_INCLUDED */

