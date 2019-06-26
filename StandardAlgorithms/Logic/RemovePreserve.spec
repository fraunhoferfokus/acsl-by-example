#ifndef REMOVEPRESERVE_SPEC_INCLUDED
#define REMOVEPRESERVE_SPEC_INCLUDED

#include "Remove.spec"

/*@
  lemma RemovePreserve{K,L}:
    \forall value_type *a, *b, v, integer i, k, n;
      0 <= k <= i < n                                  ==>
      \at(k,K) == RemoveSize{K}(a, i, v)               ==>
      \at(k,L)-1 == RemoveSize{L}(a, i, v)             ==>
      RemoveSize{L}(a, i, v) == RemoveSize{K}(a, i, v) ==>
      Remove{K}(a, i, b, v)                            ==>
      Remove{L}(a, i, b, v);
*/

#endif /* REMOVEPRESERVE_SPEC_INCLUDED */
