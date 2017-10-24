
#ifndef EQUALRANGESPRESERVESCOUNT_H_INCLUDED
#define EQUALRANGESPRESERVESCOUNT_H_INCLUDED

#include "EqualRanges.h"
#include "CountSection.h"

/*@
   lemma
     EqualRangesPreservesCount{K,L}:
       \forall value_type *a, v, integer m, n, p;
         0 <= m <= n                   ==>
         EqualRanges{K,L}(a, m, n, p)  ==>
         Count{K}(a, m, n, v) == Count{L}(a, p, p + (n-m), v);
*/

#endif /* EQUALRANGESPRESERVESCOUNT_H_INCLUDED */

