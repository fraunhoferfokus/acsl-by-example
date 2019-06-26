
#ifndef REMOVE_COPY_H_INCLUDED
#define REMOVE_COPY_H_INCLUDED

#include "HasValue.spec"
#include "Unchanged.spec"
#include "RemoveSize.spec"

/*@
  requires valid: \valid_read(a + (0..n-1));
  requires valid: \valid(b + (0..n-1));
  requires sep:   \separated(a + (0..n-1), b + (0..n-1));

  assigns b[0..n-1];

  ensures size:      \result == RemoveSize(a, n, v);
  ensures bound:     0 <= \result <= n;
  ensures discard:   !HasValue(b, \result, v);
  ensures unchanged: Unchanged{Old, Here}(b, \result, n);
*/
size_type
remove_copy2(const value_type* a, size_type n, value_type* b, value_type v);

#endif /* REMOVE_COPY_H_INCLUDED */

