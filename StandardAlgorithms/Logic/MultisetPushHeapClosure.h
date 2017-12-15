
#ifndef MULTISETPUSHHEAPCLOSURE_H_INCLUDED
#define MULTISETPUSHHEAPCLOSURE_H_INCLUDED

#include "CountLemmas.h"
#include "MultisetAdd.h"
#include "MultisetMinus.h"
#include "MultisetUnchanged.h"
#include "MultisetRetainRest2.h"
#include "MultisetUnchangedLemmas.h"

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


#endif /* MULTISETPUSHHEAPCLOSURE_H_INCLUDED */

