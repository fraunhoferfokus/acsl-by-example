
#ifndef UNIQUE_COPY3_H_INCLUDED
#define UNIQUE_COPY3_H_INCLUDED

#include "HasEqualNeighbors.spec"
#include "Unchanged.spec"

/*@
  requires valid:    \valid_read(a + (0..n-1));
  requires valid:    \valid(b + (0..n-1));
  requires sep:      \separated(a + (0..n-1), b + (0..n-1));
  assigns            b[0..n-1];
  ensures result:    0 <= \result <= n;
  ensures solitary:  !HasEqualNeighbors (b, \result);
  ensures unchanged: Unchanged{Old,Here}(b, \result, n);
  ensures unchanged: Unchanged{Old,Here}(a, n);
 */
size_type
unique_copy3(const value_type* a, size_type n, value_type* b);

#endif /* UNIQUE_COPY3_H_INCLUDED */

