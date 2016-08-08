
#ifndef MULTISETUNCHANGEDLEMMAS_H_INCLUDED
#define MULTISETUNCHANGEDLEMMAS_H_INCLUDED

#include "MultisetUnchanged.h"
#include "Unchanged.h"
#include "CountLemmas.h"

/*@
  lemma
    UnchangedImpliesMultisetUnchanged{L1,L2}:
      \forall value_type *a, integer k, n;
        Unchanged{L1,L2}(a, k, n) ==>
        MultisetUnchanged{L1,L2}(a, k, n);

      
  lemma
    MultisetUnchangedUnion{L1,L2}:
      \forall value_type *a, integer k, n;
        0 <= k <= n                        ==>
        MultisetUnchanged{L1,L2}(a, 0, k)  ==>
        MultisetUnchanged{L1,L2}(a, k, n)  ==>
        MultisetUnchanged{L1,L2}(a, 0, n); 


  lemma
    MultisetUnchangedTransitive{L1,L2,L3}:
      \forall value_type *a, integer n;
        MultisetUnchanged{L1,L2}(a, n)  ==>
        MultisetUnchanged{L2,L3}(a, n)  ==>
        MultisetUnchanged{L1,L3}(a, n);
*/

#endif /* MULTISETUNCHANGEDLEMMAS_H_INCLUDED */

