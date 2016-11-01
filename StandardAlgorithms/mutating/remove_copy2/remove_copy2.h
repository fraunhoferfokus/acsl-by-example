#ifndef REMOVE_COPY_H_INCLUDED
#define REMOVE_COPY_H_INCLUDED

#include "HasValue.h"
#include "MultisetRetainRest.h"
#include "RemoveMapping.h"
#include "Unchanged.h"

/*@
  requires valid:  \valid_read(a + (0..n-1));
  requires valid:  \valid(b + (0..n-1));
  requires sep:    \separated(a + (0..n-1), b+(0..n-1));

  assigns  b[0..(n-1)];

  ensures  bound:      0 <= \result <= n;
  ensures  size:       \result == RemoveCount(a, n, v);
  ensures  retain:     MultisetRetainRest{Here,Here}(a, n, b, \result, v);
  ensures  discard:    !HasValue(b, \result, v);
  ensures  mapping:    RemoveMapping{Here,Here}(a, n, b, v);
  ensures  unchanged:  Unchanged{Old,Here}(b, \result, n);
  ensures  unchanged:  Unchanged{Old,Here}(a, n);
*/
size_type
remove_copy(const value_type* a, size_type n, value_type* b, value_type v);

#endif /* REMOVE_COPY_H_INCLUDED */

