
#ifndef MULTISETADDDISTINCT_H_INCLUDED
#define MULTISETADDDISTINCT_H_INCLUDED

#include "MultisetAdd.h"

/*@
  lemma
    MultisetAddDistinct{K,L}:
      \forall value_type *a, v, integer i, n;
        0 <= i < n                         ==>
        \at(a[i],K) != v                   ==>
        \at(a[i],L) == v                   ==>
        MultisetUnchanged{K,L}(a, 0, i)    ==>
        MultisetUnchanged{K,L}(a, i+1, n)  ==>
        MultisetAdd{K,L}(a, n, v);
*/

#endif /* MULTISETADDDISTINCT_H_INCLUDED */

