
#ifndef REMOVE_H_INCLUDED
#define REMOVE_H_INCLUDED

#include "Remove.spec"
#include "SomeNone.spec"

/*@
  requires valid:    \valid(a + (0..n-1));
  assigns            a[0..n-1];
  ensures size:      \result == CountNotEqual{Old}(a, n, v);
  ensures bound:     0 <= \result <= n;
  ensures remove:    Remove{Old,Here}(a, n, v);
  ensures discard:   NoneEqual{Here}(a, \result, v);
  ensures unchanged: Unchanged{Old,Here}(a, \result, n);
*/
size_type
remove(value_type* a, size_type n, value_type v);

#endif /* REMOVE_H_INCLUDED */

