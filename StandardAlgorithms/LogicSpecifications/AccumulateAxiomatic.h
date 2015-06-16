
#ifndef ACCUMULATEAXIOMATIC_H_INCLUDED
#define ACCUMULATEAXIOMATIC_H_INCLUDED

#include "EqualRanges.h"

/*@
   axiomatic AccumulateAxiomatic 
   {
      logic integer Accumulate{L}(value_type* a, integer n,
                                  value_type init) reads a[0..n-1]; 

      axiom AccumulateEmpty: \forall value_type *a, init, integer n;
           n <= 0 ==> Accumulate(a, n, init) == init;

      axiom AccumulateNext: \forall value_type *a, init, integer n;
           n >= 0 ==> Accumulate(a, n + 1, init) ==
                       Accumulate(a, n, init) + a[n];

      axiom AccumulateRead{L1,L2}:
        \forall value_type *a, init, integer n;
           EqualRanges{L1,L2}(a, n) ==>
           Accumulate{L1}(a, n, init) == Accumulate{L2}(a, n, init);
   }

   // overloaded version
   logic integer Accumulate{L}(value_type* a, integer n) =
                 Accumulate{L}(a, n, (value_type) 0);
*/

#endif /* ACCUMULATEAXIOMATIC_H_INCLUDED */

