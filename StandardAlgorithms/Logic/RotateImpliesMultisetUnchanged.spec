
#ifndef ROTATEIMPLIESMULTISETUNCHANGED_SPEC_INCLUDED
#define ROTATEIMPLIESMULTISETUNCHANGED_SPEC_INCLUDED

#include "EqualRanges.spec"
#include "MultisetUnchanged.spec"
#include "EqualRangesPreservesCount.spec"

/*@
   lemma
     RotateImpliesMultisetUnchanged{K,L}:
       \forall value_type* a, integer m, n;
         0 <= m <= n                          ==>
         EqualRanges{K,L}(a, m, n, m+1)     ==>
         EqualRanges{K,L}(a, n, n+1, m)     ==>
         MultisetUnchanged{K,L}(a, m, n+1);
*/

#endif /* ROTATEIMPLIESMULTISETUNCHANGED_SPEC_INCLUDED */

