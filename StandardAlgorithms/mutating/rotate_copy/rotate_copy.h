
#ifndef ROTATE_COPY_H_INCLUDED
#define ROTATE_COPY_H_INCLUDED

#include "EqualRanges.h"
#include "Unchanged.h"

/*@
  requires bound: 0 <= m <= n;
  requires valid: \valid_read(a + (0..n-1));
  requires valid:      \valid(b + (0..n-1));
  requires sep:    \separated(a + (0..n-1), b + (0..n-1));

  assigns b[0..(n-1)];

  ensures left:      EqualRanges{Here,Old}(b, 0, n-m, a, m);
  ensures right:     EqualRanges{Here,Old}(b, n-m, n, a, 0);
  ensures unchanged:   Unchanged{Here,Old}(a, n);
*/
void rotate_copy(const value_type* a, size_type m, size_type n, value_type* b);

#endif /* ROTATE_COPY_H_INCLUDED */

