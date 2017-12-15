
#ifndef ACCUMULATEAXIOMATIC_H_INCLUDED
#define ACCUMULATEAXIOMATIC_H_INCLUDED

#include "Unchanged.h"

/*@
   axiomatic AccumulateAxiomatic 
   {
     logic value_type
     Accumulate{L}(value_type* a, integer n, value_type init) reads a[0..n-1]; 

     axiom
       AccumulateEmpty{L}:
         \forall value_type *a, init, integer n;
           n <= 0 ==> Accumulate(a, n, init) == init;

     axiom
       AccumulateNext{L}:
         \forall value_type *a, init, integer n;
           0 < n ==> Accumulate(a, n, init) == Accumulate(a, n-1, init) + a[n-1];

     axiom
       AccumulateRead{K,L}:
         \forall value_type *a, init, integer n;
           Unchanged{K,L}(a, n) ==>
           Accumulate{K}(a, n, init) == Accumulate{L}(a, n, init);
   }
*/

#endif /* ACCUMULATEAXIOMATIC_H_INCLUDED */

