
#ifndef ACCUMULATEAXIOMATIC_H_INCLUDED
#define ACCUMULATEAXIOMATIC_H_INCLUDED

#include "Unchanged.h"

/*@
   axiomatic AccumulateAxiomatic 
   {
     logic value_type Accumulate{L}(value_type* a, integer n,
                                     value_type init) reads a[0..n-1]; 

     axiom AccumulateEmpty:
       \forall value_type *a, init, integer n;
         n <= 0 ==> Accumulate(a, n, init) == init;

     axiom AccumulateNext:
       \forall value_type *a, init, integer n;
         n > 0 ==>
         Accumulate(a, n, init) == Accumulate(a, n-1, init) + a[n-1];

     axiom AccumulateRead{L1,L2}:
       \forall value_type *a, init, integer n;
          Unchanged{L1,L2}(a, n) ==>
          Accumulate{L1}(a, n, init) == Accumulate{L2}(a, n, init);
   }
*/

#endif /* ACCUMULATEAXIOMATIC_H_INCLUDED */

