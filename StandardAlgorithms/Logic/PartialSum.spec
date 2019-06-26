
#ifndef PARTIALSUM_SPEC_INCLUDED
#define PARTIALSUM_SPEC_INCLUDED

#include "AccumulateDefault.spec"

/*@
  predicate
    PartialSum{L}(value_type* a, integer n, value_type* b) =
      \forall integer i; 0 <= i < n ==> Accumulate(a, i+1) == b[i];
*/

#endif /* PARTIALSUM_SPEC_INCLUDED */

