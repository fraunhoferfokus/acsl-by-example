
#ifndef UNIQUE_COPY_H_INCLUDED
#define UNIQUE_COPY_H_INCLUDED

#include "HasEqualNeighbors.h"
#include "Unchanged.h"

/*@
  requires valid: \valid_read(a + (0..n-1));
  requires valid: \valid(b + (0..n-1));
  requires sep:   \separated(a + (0..n-1), b + (0..n-1));

  assigns b[0..n-1];

  ensures result:    0 <= \result <= n;
  ensures unique:    !HasEqualNeighbors (b, \result);
  ensures unchanged: Unchanged{Old, Here}(b, \result, n);
 */
size_type
unique_copy(const value_type* a, size_type n, value_type* b);

#endif /* UNIQUE_COPY_H_INCLUDED */

