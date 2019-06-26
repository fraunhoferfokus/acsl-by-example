
#ifndef MULTISETPUSHHEAPRETAIN_SPEC_INCLUDED
#define MULTISETPUSHHEAPRETAIN_SPEC_INCLUDED

#include "CountLemmas.spec"
#include "MultisetAdd.spec"
#include "MultisetMinus.spec"
#include "MultisetUnchanged.spec"
#include "MultisetRetainRest2.spec"
#include "MultisetUnchangedLemmas.spec"

/*@
 lemma
   MultisetPushHeapRetain{K,L,M}:
     \forall value_type *a, ap, ah, v, integer h, p, n;
       0 <= p < h < n-1                      ==>
       ah < ap < v                           ==>
       \at(a[h],L)  ==  ah                   ==>
       \at(a[p],L)  ==  ap                   ==>
       \at(a[h],M)  ==  ap                   ==>
       MultisetMinus{K,L}(a, n, v)           ==>
       MultisetAdd{K,L}(a, n, ah)            ==>
       MultisetRetainRest{K,L}(a, n, v, ah)  ==>
       MultisetUnchanged{L,M}(a, 0, h)       ==>
       MultisetUnchanged{L,M}(a, h+1, n)     ==>
       MultisetRetainRest{K,M}(a, n, v, ap);
*/


#endif /* MULTISETPUSHHEAPRETAIN_SPEC_INCLUDED */

