
#ifndef MERGE_SORT_H_INCLUDED
#define MERGE_SORT_H_INCLUDED

#include "MultisetReorder.acsl"
#include "Increasing.acsl"

/*@
  requires   valid:       \valid(a + (0..n-1));
  requires   valid:       \valid(b + (0..n-1));
  requires   sep:         \separated(a + (0..n-1), b + (0..n-1));

  terminates              \true;
  decreases               n;
  exits                   \false;
  assigns                 a[0..n-1], b[0..n-1];

  ensures    reorder:     MultisetReorder{Old,Here}(a, n);
  ensures    increasing:  Increasing(a, n);
*/
void merge_sort(value_type* a, size_type n, value_type* b);

#endif /* MERGE_SORT_H_INCLUDED */

