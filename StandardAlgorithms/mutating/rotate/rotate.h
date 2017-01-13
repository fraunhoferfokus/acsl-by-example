
#ifndef ROTATE_H_INCLUDED
#define ROTATE_H_INCLUDED

#include "EqualRanges.h"

/*@
  requires valid: \valid(a + (0..n-1));
  requires bound: m <= n;

  assigns a[0..n-1];

  ensures result: \result == n-m;
  ensures left:   EqualRanges{Here,Old}(a, 0, n-m, m);
  ensures right:  EqualRanges{Here,Old}(a, n-m, n, 0);
*/
size_type rotate(value_type* a, size_type m, size_type n);

#endif  /* ROTATE_H_INCLUDED */

