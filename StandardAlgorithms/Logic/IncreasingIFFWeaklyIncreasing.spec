
#ifndef INCREASINGIFFWEAKLYINCREASING_SPEC_INCLUDED
#define INCREASINGIFFWEAKLYINCREASING_SPEC_INCLUDED

#include "Increasing.spec"
#include "WeaklyIncreasing.spec"

/*@
  lemma
    IncreasingImpliesWeaklyIncreasing{L}:
      \forall value_type* a, integer m, n;
        0 <= m <= n                 ==>
        Increasing(a, m, n)         ==>
        WeaklyIncreasing(a, m, n);

  lemma
    WeaklyIncreasingImpliesIncreasing{L}:
      \forall value_type* a, integer m, n;
        0 <= m <= n                ==>
        WeaklyIncreasing(a, m, n)  ==>
        Increasing(a, m, n);
*/

#endif /* INCREASINGIFFWEAKLYINCREASING_SPEC_INCLUDED */

