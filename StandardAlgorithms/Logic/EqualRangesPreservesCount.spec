
#ifndef EQUALRANGESPRESERVESCOUNT_SPEC_INCLUDED
#define EQUALRANGESPRESERVESCOUNT_SPEC_INCLUDED

#include "EqualRanges.spec"
#include "CountSection.spec"

/*@
   lemma
     EqualRangesPreservesCount{K,L}:
       \forall value_type *a, v, integer m, n, p;
         0 <= m <= n                   ==>
         EqualRanges{K,L}(a, m, n, p)  ==>
         Count{K}(a, m, n, v) == Count{L}(a, p, p + (n-m), v);
*/

#endif /* EQUALRANGESPRESERVESCOUNT_SPEC_INCLUDED */

