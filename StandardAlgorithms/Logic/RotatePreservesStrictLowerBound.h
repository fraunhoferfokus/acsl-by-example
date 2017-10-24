
#ifndef ROTATEPRESERVESSTRICTLOWERBOUND_H_INCLUDED
#define ROTATEPRESERVESSTRICTLOWERBOUND_H_INCLUDED

#include "StrictLowerBound.h"
#include "EqualRanges.h"

/*@
   lemma
     RotatePreservesStrictLowerBound{K,L}:
       \forall value_type* a, integer m, n;
         StrictLowerBound{K}(a, m, n, \at(a[n],K)) ==>
         EqualRanges{K,L}(a, m, n, m+1)          ==>
         EqualRanges{K,L}(a, n, n+1, m)          ==>
         StrictLowerBound{L}(a, m+1, n+1, \at(a[m],L));
*/

#endif /* ROTATEPRESERVESSTRICTLOWERBOUND_H_INCLUDED */

