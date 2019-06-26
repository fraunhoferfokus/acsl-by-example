
#ifndef UNIQUE_COPY4_H_INCLUDED
#define UNIQUE_COPY4_H_INCLUDED

#include "Unique.spec"
#include "UniqueImpliesNoEqualNeighbors.spec"


/*@
  requires valid: \valid_read(a + (0..n-1));
  requires valid: \valid(b + (0..n-1));
  requires sep:   \separated(a + (0..n-1), b + (0..n-1));

  assigns b[0..n-1];

  ensures bound:     0 <= \result <= n;
  ensures size:      \result == UniqueSize(a, n);
  ensures unique:    Unique(a, n, b);
  ensures unchanged: Unchanged{Old, Here}(a, n);
  ensures unchanged: Unchanged{Old, Here}(b, \result, n);
 */
size_type
unique_copy4(const value_type* a, size_type n, value_type* b);

#endif /* UNIQUE_COPY4_H_INCLUDED */

