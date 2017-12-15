
#ifndef MULTISETRETAINRESTMISS_H_INCLUDED
#define MULTISETRETAINRESTMISS_H_INCLUDED

#include "MultisetRetainRest.h"
#include "RemoveCount.h"

/*@
  lemma
    MultisetRetainRestMiss{K,L}:
      \forall value_type *a, *b, v, integer m, n;
        0 <= m  ==>  0 <= n                     ==>
        n == RemoveCount{K}(a, m, v)            ==>
        MultisetRetainRest{K,K}(a, m, b, n, v)  ==>
        \at(a[m],K) != v                        ==>
        \at(a[m],L) == \at(b[n],L)              ==>
        Unchanged{K,L}(a,m+1)                   ==>
        Unchanged{K,L}(b,n)                     ==>
        n+1  == RemoveCount{L}(a, m+1, v)       ==>
        MultisetRetainRest{K,L}(a, m+1, b, n+1, v);
*/

#endif /* MULTISETRETAINRESTMISS_H_INCLUDED */

