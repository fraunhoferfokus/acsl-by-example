
#ifndef PARTIAL_SORT_H_INCLUDED
#define PARTIAL_SORT_H_INCLUDED

#include "Sorted.spec"
#include "Partition.spec"
#include "MultisetUnchanged.spec"

/*@
  requires valid: \valid(a + (0..n-1));
  requires split: 0 <= m <= n;

  assigns  a[0..n-1];

  ensures sorted:    Sorted(a, m);
  ensures partition: Partition(a, m, n);
  ensures reorder:   MultisetUnchanged{Old,Here}(a, n);
*/
void
partial_sort(value_type* a, size_type m, size_type n);

#endif /* PARTIAL_SORT_H_INCLUDED */

