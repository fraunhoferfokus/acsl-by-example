
#ifndef REMOVE_COPY2_H_INCLUDED
#define REMOVE_COPY2_H_INCLUDED

#include "HasValue.h"
#include "Unchanged.h"
#include "RetainAllButOne.h"
#include "RemoveMapping.h"

/*@
  requires valid: \valid_read(a + (0..n-1));
  requires valid:      \valid(b + (0..n-1));
  requires sep:    \separated(a + (0..n-1), b+(0..n-1));

  assigns  b[0..(n-1)];

  ensures  bound:      0 <= \result <= n;
  ensures  result:     \result == RemoveCount(a, n, v);
  ensures  retain:     RetainAllButOne(a, n, b, \result, v);
  ensures  discard:    !HasValue(b, \result, v);
  ensures  stable:     RemoveMapping(a, n, b, v);
  ensures  unchanged:  Unchanged{Here,Old}(b, \result, n);
  ensures  unchanged:  Unchanged{Here,Old}(a, n);
*/
size_type remove_copy(const value_type* a, size_type  n,
                      value_type* b, value_type v);

#endif /* REMOVE_COPY2_H_INCLUDED */

