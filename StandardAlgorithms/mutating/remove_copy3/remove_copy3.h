
#ifndef REMOVE_COPY_SPEC_INCLUDED
#define REMOVE_COPY_SPEC_INCLUDED

#include "Unchanged.spec"
#include "Remove.spec"
#include "RemoveImpliesNotHasValue.spec"

/*@
  requires valid:    \valid_read(a + (0..n-1));
  requires valid:    \valid(b + (0..n-1));
  requires sep:      \separated(a + (0..n-1), b);
  assigns            b[0..n-1];
  ensures size:      \result == RemoveSize{Old}(a, n, v);
  ensures bound:     0 <= \result <= n;
  ensures remove:    Remove{Old,Here}(a, n, b, v);
  ensures discard:   !HasValue(b, \result, v);
  ensures unchanged: Unchanged{Old, Here}(a, n);
  ensures unchanged: Unchanged{Old, Here}(b, \result,   n);
*/
size_type
remove_copy3(const value_type* a, size_type n, value_type* b, value_type v);

#endif /* REMOVE_COPY_H_INCLUDED */

