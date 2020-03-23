
#ifndef MULTISETUNCHANGED_SPEC_INCLUDED
#define MULTISETUNCHANGED_SPEC_INCLUDED

#include "Count.spec"

/*@
  axiomatic MultisetUnchanged
  {
    predicate
    MultisetUnchanged{L1,L2}(value_type* a, integer first, integer last) =
      \forall value_type v;
        Count{L1}(a, first, last, v) == Count{L2}(a, first, last, v);

    predicate
    MultisetUnchanged{L1,L2}(value_type* a, integer n) =
      MultisetUnchanged{L1,L2}(a, 0, n);

    lemma UnchangedImpliesMultisetUnchanged{L1,L2}:
      \forall value_type *a, integer k, n;
        Unchanged{L1,L2}(a, k, n)  ==>
        MultisetUnchanged{L1,L2}(a, k, n);

    lemma MultisetUnchangedUnion{L1,L2}:
      \forall value_type *a, integer i, k, n;
        0 <= i <= k <= n                   ==>
        MultisetUnchanged{L1,L2}(a, i, k)  ==>
        MultisetUnchanged{L1,L2}(a, k, n)  ==>
        MultisetUnchanged{L1,L2}(a, i, n);

    lemma MultisetUnchangedTransitive{L1,L2,L3}:
      \forall value_type *a, integer n;
        MultisetUnchanged{L1,L2}(a, n)  ==>
        MultisetUnchanged{L2,L3}(a, n)  ==>
        MultisetUnchanged{L1,L3}(a, n);
  }
*/

#endif /* MULTISETUNCHANGED_SPEC_INCLUDED */

