
#ifndef EQUALRANGESPRESERVESSORTED_SPEC_INCLUDED
#define EQUALRANGESPRESERVESSORTED_SPEC_INCLUDED

#include "Sorted.spec"
#include "EqualRanges.spec"

/*@
   lemma
     EqualRangesPreservesSorted{K,L}:
       \forall value_type* a, integer m, n, p;
         Sorted{K}(a, m, n)              ==>
         EqualRanges{K,L}(a, m, n, m+p)  ==>
         Sorted{L}(a, m+p, n+p);
*/

#endif /* EQUALRANGESPRESERVESSORTED_SPEC_INCLUDED */

