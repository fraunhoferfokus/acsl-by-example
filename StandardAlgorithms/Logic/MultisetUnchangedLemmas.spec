
#ifndef MULTISETUNCHANGEDLEMMAS_SPEC_INCLUDED
#define MULTISETUNCHANGEDLEMMAS_SPEC_INCLUDED

#include "Unchanged.spec"
#include "CountLemmas.spec"
#include "MultisetUnchanged.spec"

/*@
  lemma
    UnchangedImpliesMultisetUnchanged{L1,L2}:
      \forall value_type *a, integer k, n;
        Unchanged{L1,L2}(a, k, n) ==>
        MultisetUnchanged{L1,L2}(a, k, n);


  lemma
    MultisetUnchangedUnion{L1,L2}:
      \forall value_type *a, integer i, k, n;
        0 <= i <= k <= n                   ==>
        MultisetUnchanged{L1,L2}(a, i, k)  ==>
        MultisetUnchanged{L1,L2}(a, k, n)  ==>
        MultisetUnchanged{L1,L2}(a, i, n);


  lemma
    MultisetUnchangedTransitive{L1,L2,L3}:
      \forall value_type *a, integer n;
        MultisetUnchanged{L1,L2}(a, n)  ==>
        MultisetUnchanged{L2,L3}(a, n)  ==>
        MultisetUnchanged{L1,L3}(a, n);
*/

#endif /* MULTISETUNCHANGEDLEMMAS_SPEC_INCLUDED */

