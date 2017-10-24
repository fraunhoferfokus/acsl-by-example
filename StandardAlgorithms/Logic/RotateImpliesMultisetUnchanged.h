
#ifndef ROTATEIMPLIESMULTISETUNCHANGED_H_INCLUDED
#define ROTATEIMPLIESMULTISETUNCHANGED_H_INCLUDED

#include "EqualRanges.h"
#include "MultisetUnchanged.h"
#include "EqualRangesPreservesCount.h"

/*@
   lemma
     RotateImpliesMultisetUnchanged{K,L}:
       \forall value_type* a, integer m, n;
         0 <= m <= n                          ==>
         EqualRanges{K,L}(a, m, n, m+1)     ==>
         EqualRanges{K,L}(a, n, n+1, m)     ==>
         MultisetUnchanged{K,L}(a, m, n+1);
*/

#endif /* ROTATEIMPLIESMULTISETUNCHANGED_H_INCLUDED */

