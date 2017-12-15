
#ifndef ACCUMULATEDEFAULT_H_INCLUDED
#define ACCUMULATEDEFAULT_H_INCLUDED

#include "AccumulateAxiomatic.h"

/*@
  logic value_type Accumulate{L}(value_type* a, integer n) = 
    Accumulate{L}(a, n, (value_type) 0);

  lemma
    AccumulateDefault0{L}:
      \forall value_type* a; Accumulate(a, 0) == 0;

  lemma
    AccumulateDefault1{L}:
      \forall value_type* a; Accumulate(a, 1) == a[0];

  lemma
    AccumulateDefaultNext{L}:
      \forall value_type* a, integer n;
        n >= 0 ==> Accumulate(a, n+1) == Accumulate(a, n) + a[n];

  lemma
    AccumulateDefaultRead{L1,L2}:
      \forall value_type *a, integer n;
        Unchanged{L1,L2}(a, n) ==>
        Accumulate{L1}(a, n) == Accumulate{L2}(a, n);
*/

#endif /* ACCUMULATEDEFAULT_H_INCLUDED */

