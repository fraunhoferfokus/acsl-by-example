
#ifndef MULTISETUNCHANGEDLEMMAS_H_INCLUDED
#define MULTISETUNCHANGEDLEMMAS_H_INCLUDED

#include "MultisetUnchanged.h"
#include "CountLemmas.h"
#include "Unchanged.h"

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

#endif /* MULTISETUNCHANGEDLEMMAS_H_INCLUDED */

