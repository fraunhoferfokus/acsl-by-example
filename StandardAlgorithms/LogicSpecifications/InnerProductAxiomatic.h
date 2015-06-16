
#ifndef INNERPRODUCTAXIOMATIC_H_INCLUDED
#define INNERPRODUCTAXIOMATIC_H_INCLUDED

#include "EqualRanges.h"

/*@
   axiomatic InnerProductAxiomatic
   {
     logic integer
     InnerProduct{L}(value_type* a, value_type* b, integer n,
                     value_type init) reads a[0..n-1], b[0..n-1];

     axiom InnerProductEmpty:
       \forall value_type *a, *b, init, integer n;
         n <= 0 ==> InnerProduct(a, b, n, init) == init;

     axiom InnerProductNext:
       \forall value_type *a, *b, init, integer n;
         n >= 0 ==> InnerProduct(a, b, n + 1, init) ==
                    InnerProduct(a, b, n, init) + (a[n] * b[n]);

     axiom InnerProductRead{L1,L2}:
       \forall value_type *a, *b, init, integer n;
         EqualRanges{L1,L2}(a, n) && EqualRanges{L1,L2}(b, n) ==>
           InnerProduct{L1}(a, b, n, init) ==
           InnerProduct{L2}(a, b, n, init);
   }
   
*/

#endif /* INNERPRODUCTAXIOMATIC_H_INCLUDED */

