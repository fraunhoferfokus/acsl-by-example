#ifndef REMOVE_COPY_H_INCLUDED
#define REMOVE_COPY_H_INCLUDED

#include "HasValue.h"
#include "Unchanged.h"
#include "MultisetRetainRest.h"

/*@
  requires valid: \valid_read(a + (0..n-1));
  requires valid:      \valid(b + (0..n-1));
  requires sep:    \separated(a + (0..n-1), b);

  assigns  b[0..n-1];

  ensures  bound:      0 <= \result <= n;
  ensures  size:       \result == n - Count{Old}(a, n, v);
  ensures  retain:     MultisetRetainRest{Old,Here}(a, n, b, \result, v);
  ensures  discard:    !HasValue(b, \result, v);
  ensures  unchanged:  Unchanged{Old,Here}(b, \result, n);
*/
size_type
remove_copy(const value_type* a, size_type n, value_type* b, value_type v);

#endif /* REMOVE_COPY_H_INCLUDED */

