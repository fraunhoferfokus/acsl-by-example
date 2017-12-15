
#ifndef MULTISETRETAINRESTUNCHANGED_H_INCLUDED
#define MULTISETRETAINRESTUNCHANGED_H_INCLUDED

#include "MultisetRetainRest.h"

/*@
  lemma
    MultisetRetainRestUnchanged{K,L}:
      \forall value_type *a, *b, v, integer m, n;
        0 <= m  ==>  0 <= n                     ==>
        n == RemoveCount{L}(a, m, v)            ==>
        MultisetRetainRest{K,L}(a, m, b, n, v)  ==>
        Unchanged{K,L}(a,m)                     ==>
        MultisetRetainRest{L,L}(a, m, b, n, v);
*/

#endif /* MULTISETRETAINRESTUNCHANGED_H_INCLUDED */

