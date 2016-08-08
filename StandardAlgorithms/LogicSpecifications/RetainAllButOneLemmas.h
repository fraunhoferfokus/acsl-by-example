
#ifndef RETAINALLBUTONELEMMAS_H_INCLUDED
#define RETAINALLBUTONELEMMAS_H_INCLUDED

#include "RetainAllButOne.h"

/*@
  lemma RetainAllButOneMiss{K,L}:
    \forall value_type *a, *b, v, integer m, n;
       0 <= m  ==>  0 <= n               ==>
       RetainAllButOne{K}(a, m, b, n, v) ==>
       \at(a[m],K) != v                  ==>
       \at(a[m],L) == \at(b[n],L)        ==>
       Unchanged{K,L}(a,m+1)             ==>
       Unchanged{K,L}(b,n)               ==>
       RetainAllButOne{L}(a, m+1, b, n+1, v);
*/

#endif /* RETAINALLBUTONELEMMAS_H_INCLUDED */

