
#ifndef REVERSELEMMAS_H_INCLUDED
#define REVERSELEMMAS_H_INCLUDED

#include "ReverseLogic.h"
#include "EqualRanges.h"
#include "Unchanged.h"

/*@
   lemma ReverseShift{K,L}:
     \forall value_type* a, integer p, q;
       Reverse{K,L}(a+p, q-p) ==> Reverse{K,L}(a, p, q);

  lemma ReverseIdempotentLeft{K,L,M}:
    \forall value_type* a, integer m, n;
      Reverse{L,K}(a, m, n, m)   ==>
      Reverse{M,L}(a, 0, n-m, m) ==>
      EqualRanges{M,K}(a, 0, n-m, m);

  lemma ReverseIdempotentRight{K,L,M}:
    \forall value_type* a, integer m, n;
      Reverse{L,K}(a, 0, m, 0)   ==>
      Reverse{M,L}(a, n-m, n, 0) ==>
      EqualRanges{M,K}(a, n-m, n, 0);
*/

#endif /* REVERSELEMMAS_H_INCLUDED */

