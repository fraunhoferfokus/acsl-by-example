
#ifndef MULTISETOPERATIONS_SPEC_INCLUDED
#define MULTISETOPERATIONS_SPEC_INCLUDED

#include "MultisetUnchanged.spec"

/*@
  axiomatic MultisetOperations
  {
    predicate
    MultisetAdd{K,L}(value_type* a, integer n, value_type val) =
      Count{L}(a, n, val) == Count{K}(a, n, val) + 1;

    predicate
    MultisetMinus{K,L}(value_type* a, integer n, value_type val) =
      Count{L}(a, n, val) == Count{K}(a, n, val) - 1;

    lemma MultisetAddDistinct{K,L}:
      \forall value_type *a, v, integer i, n;
        0 <= i < n                         ==>
        \at(a[i],K) != v                   ==>
        \at(a[i],L) == v                   ==>
        MultisetUnchanged{K,L}(a, 0, i)    ==>
        MultisetUnchanged{K,L}(a, i+1, n)  ==>
        MultisetAdd{K,L}(a, n, v);

    lemma MultisetMinusDistinct{K,L}:
      \forall value_type *a, v, integer i, n;
        0 <= i < n                         ==>
        \at(a[i],K) == v                   ==>
        \at(a[i],L) != v                   ==>
        MultisetUnchanged{K,L}(a, 0, i)    ==>
        MultisetUnchanged{K,L}(a, i+1, n)  ==>
        MultisetMinus{K,L}(a, n, v);
  }
*/

#endif /* MULTISETOPERATIONS_SPEC_INCLUDED */

