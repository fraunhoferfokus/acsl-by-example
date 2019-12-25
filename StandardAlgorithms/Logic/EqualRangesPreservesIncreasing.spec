
#ifndef EQUALRANGESPRESERVESINCREASING_SPEC_INCLUDED
#define EQUALRANGESPRESERVESINCREASING_SPEC_INCLUDED

#include "Increasing.spec"
#include "EqualRanges.spec"

/*@
   lemma
     EqualRangesPreservesIncreasing{K,L}:
       \forall value_type* a, integer m, n, p;
         Increasing{K}(a, m, n)              ==>
         EqualRanges{K,L}(a, m, n, m+p)  ==>
         Increasing{L}(a, m+p, n+p);
*/

#endif /* EQUALRANGESPRESERVESINCREASING_SPEC_INCLUDED */

