
#ifndef PARTIALSUM_H_INCLUDED
#define PARTIALSUM_H_INCLUDED

#include "AccumulateAxiomatic.h"

/*@
  predicate
    PartialSum(value_type* a, integer n, value_type* b) = 
      \forall integer i; 0 <= i < n ==>
        b[i] == Accumulate(a, i+1);
*/

#endif /* PARTIALSUM_H_INCLUDED */

