
#ifndef REMOVE_COPY2_H_INCLUDED
#define REMOVE_COPY2_H_INCLUDED

#include "HasValue.h"
#include "Unchanged.h"
#include "CountAxiomatic.h"
#include "PreserveCount.h"
#include "StableRemove.h"

/*@
  requires valid_a: \valid_read(a + (0..n-1));
  requires valid_b:      \valid(b + (0..n-1));
  requires sep:      \separated(a + (0..n-1), b+(0..n-1));

  assigns  b[0..(n-1)];

  ensures  bound:      0 <= \result <= n;
  ensures  result:     \result == RemoveCount(a, n, v);
  ensures  removed:    !HasValue(b, \result, v);
  ensures  kept:       PreserveCount(a, n, b, \result, v);
  ensures  unchanged:  Unchanged{Here,Old}(b, \result, n);
  ensures  stable:     StableRemove(a, n, b, v);
*/
size_type remove_copy(const value_type* a, size_type  n,
                      value_type* b, value_type v);

#endif /* REMOVE_COPY2_H_INCLUDED */

