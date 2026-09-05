
#ifndef INPLACE_MERGE_H_INCLUDED
#define INPLACE_MERGE_H_INCLUDED

#include "Increasing.acsl"
#include "MultisetReorder.acsl"

/*@
  requires   valid:       \valid(a + (0..n-1));
  requires   split:       0 <= m <= n;
  requires   increasing:  Increasing(a, m);
  requires   increasing:  Increasing(a, m, n);

  terminates              \true;
  exits                   \false;
  assigns                 a[0..n-1];

  ensures    reorder:     MultisetReorder{Old,Here}(a, n);
  ensures    increasing:  Increasing(a, n);
*/
void inplace_merge(value_type* a, size_type m, size_type n);

#endif /* INPLACE_MERGE_H_INCLUDED */
