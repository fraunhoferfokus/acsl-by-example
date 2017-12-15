
#ifndef MULTISETMINUSDISTINCT_H_INCLUDED
#define MULTISETMINUSDISTINCT_H_INCLUDED

#include "MultisetMinus.h"

/*@
  lemma
    MultisetMinusDistinct{K,L}:
      \forall value_type *a, v, integer i, n;
        0 <= i < n                         ==>
        \at(a[i],K) == v                   ==>
        \at(a[i],L) != v                   ==>
        MultisetUnchanged{K,L}(a, 0, i)    ==>
        MultisetUnchanged{K,L}(a, i+1, n)  ==>
        MultisetMinus{K,L}(a, n, v);
*/

#endif /* MULTISETMINUSDISTINCT_H_INCLUDED */

