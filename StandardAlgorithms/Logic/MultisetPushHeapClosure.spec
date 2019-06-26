
#ifndef MULTISETPUSHHEAPCLOSURE_SPEC_INCLUDED
#define MULTISETPUSHHEAPCLOSURE_SPEC_INCLUDED

#include "CountLemmas.spec"
#include "MultisetAdd.spec"
#include "MultisetMinus.spec"
#include "MultisetUnchanged.spec"
#include "MultisetRetainRest2.spec"
#include "MultisetUnchangedLemmas.spec"

/*@
 lemma
   MultisetPushHeapClosure{K,L,M}:
     \forall value_type *a, u, v, integer i, n;
       0 <= i < n-1                         ==>
       u != v                               ==>
       \at(a[i],M)  == v                    ==>
       MultisetAdd{K,L}(a, n, u)            ==>
       MultisetMinus{K,L}(a, n, v)          ==>
       MultisetRetainRest{K,L}(a, n, v, u)  ==>
       MultisetUnchanged{L,M}(a, 0, i)      ==>
       MultisetUnchanged{L,M}(a, i+1, n)    ==>
       MultisetAdd{L,M}(a, n, v)            ==>
       MultisetMinus{L,M}(a, n, u)          ==>
       MultisetUnchanged{K,M}(a, n);
*/


#endif /* MULTISETPUSHHEAPCLOSURE_SPEC_INCLUDED */

