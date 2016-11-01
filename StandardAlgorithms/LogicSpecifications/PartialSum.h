
#ifndef PARTIALSUM_H_INCLUDED
#define PARTIALSUM_H_INCLUDED

#include "AccumulateDefault.h"

/*@
  predicate
    PartialSum{L}(value_type* a, integer n, value_type* b) = 
      \forall integer i; 0 <= i < n ==> Accumulate(a, i+1) == b[i];
*/

#endif /* PARTIALSUM_H_INCLUDED */

