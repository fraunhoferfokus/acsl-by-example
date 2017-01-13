
#ifndef COPYBACKWARD_H_INCLUDED
#define COPYBACKWARD_H_INCLUDED

#include "EqualRanges.h"

/*@
  requires valid: \valid_read(a + (0..n-1));
  requires valid:      \valid(b + (0..n-1));
  requires sep:    \separated(a + (0..n-1), b + n);

  assigns  b[0..n-1];

  ensures equal: EqualRanges{Here,Old}(b, n, a);
*/
void copy_backward(const value_type* a, size_type n, value_type* b);

#endif /* COPYBACKWARD_H_INCLUDED */

