
#ifndef INNERPRODUCT_H_INCLUDED
#define INNERPRODUCT_H_INCLUDED

#include "Unchanged.h"

/*@
   axiomatic InnerProductAxiomatic
   {
     logic integer
     InnerProduct{L}(value_type* a, value_type* b, integer n,
                     value_type init) reads a[0..n-1], b[0..n-1];

     axiom
       InnerProductEmpty{L}:
         \forall value_type *a, *b, init, integer n;
           n <= 0 ==> InnerProduct(a, b, n, init) == init;

     axiom
       InnerProductNext{L}:
         \forall value_type *a, *b, init, integer n;
          0 < n  ==> InnerProduct(a, b, n, init) ==
                     InnerProduct(a, b, n-1, init) + (a[n-1] * b[n-1]);

     axiom
       InnerProductRead{K,L}:
         \forall value_type *a, *b, init, integer n;
           Unchanged{K,L}(a, n) ==>
           Unchanged{K,L}(b, n) ==>
           InnerProduct{K}(a, b, n, init) == InnerProduct{L}(a, b, n, init);
   }
*/

#endif /* INNERPRODUCT_H_INCLUDED */

