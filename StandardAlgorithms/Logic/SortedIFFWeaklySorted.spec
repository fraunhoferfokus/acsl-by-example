
#ifndef SORTEDIFFWEAKLYSORTED_SPEC_INCLUDED
#define SORTEDIFFWEAKLYSORTED_SPEC_INCLUDED

#include "Sorted.spec"
#include "WeaklySorted.spec"

/*@
  lemma
    SortedImpliesWeaklySorted{L}:
      \forall value_type* a, integer m, n;
        0 <= m <= n     ==>
        Sorted(a, m, n) ==>
        WeaklySorted(a, m, n);

  lemma
    WeaklySortedImpliesSorted{L}:
      \forall value_type* a, integer m, n;
        0 <= m <= n           ==>
        WeaklySorted(a, m, n) ==>
        Sorted(a, m, n);
*/

#endif /* SORTEDIFFWEAKLYSORTED_SPEC_INCLUDED */

