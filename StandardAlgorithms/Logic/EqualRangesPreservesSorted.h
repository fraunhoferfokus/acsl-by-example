
#ifndef EQUALRANGESPRESERVESSORTED_H_INCLUDED
#define EQUALRANGESPRESERVESSORTED_H_INCLUDED

#include "Sorted.h"
#include "EqualRanges.h"

/*@
   lemma
     EqualRangesPreservesSorted{K,L}:
       \forall value_type* a, integer m, n, p;
         Sorted{K}(a, m, n)              ==>
         EqualRanges{K,L}(a, m, n, m+p)  ==>
         Sorted{L}(a, m+p, n+p);
*/

#endif /* EQUALRANGESPRESERVESSORTED_H_INCLUDED */

