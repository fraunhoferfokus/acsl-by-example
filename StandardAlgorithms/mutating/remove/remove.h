
#ifndef REMOVE_COPY_H_INCLUDED
#define REMOVE_COPY_H_INCLUDED

#include "HasValue.h"
#include "Unchanged.h"
#include "MultisetRetainRest.h"

/*@
  requires valid: \valid(a + (0..n-1));

  assigns  a[0..(n-1)];

  ensures  bound:      0 <= \result <= n;
  ensures  size:       \result == n - Count{Old}(a, n, v);
  ensures  retain:     MultisetRetainRest{Old,Here}(a, n, a, \result, v);
  ensures  discard:    !HasValue{Here}(a, \result, v);
  ensures  unchanged:  Unchanged{Here,Old}(a, \result, n);
*/
size_type remove(value_type* a, size_type n, value_type v);

#endif /* REMOVE_COPY_H_INCLUDED */

