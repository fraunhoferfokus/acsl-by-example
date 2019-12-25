
#ifndef ROTATE_H_INCLUDED
#define ROTATE_H_INCLUDED

#include "EqualRanges.spec"

/*@
  requires valid: \valid(a + (0..n-1));
  requires bound: m <= n;
  assigns         a[0..n-1];
  ensures result: \result == n-m;
  ensures left:   EqualRanges{Old,Here}(a, 0, m, n-m);
  ensures right:  EqualRanges{Old,Here}(a, m, n, 0);
*/
size_type
rotate(value_type* a, size_type m, size_type n);

#endif  /* ROTATE_H_INCLUDED */

