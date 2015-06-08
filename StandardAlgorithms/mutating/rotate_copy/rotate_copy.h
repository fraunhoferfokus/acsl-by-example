
#ifndef ROTATE_COPY_H_INCLUDED
#define ROTATE_COPY_H_INCLUDED

#include "EqualRanges.h"

/*@
  requires sub:     0 <= m <= n;
  requires valid_a: \valid_read(a + (0..n-1));
  requires valid_b:      \valid(b + (0..n-1));
  requires sep:      \separated(a + (0..n-1), b + (0..n-1));

  assigns b[0..(n-1)];

  ensures first:  EqualRanges{Here,Here}(a,   m,   b+(n-m));
  ensures last:   EqualRanges{Here,Here}(a+m, n-m, b);
*/
void rotate_copy(const value_type* a, size_type m, size_type n,
                 value_type* b);

#endif /* ROTATE_COPY_H_INCLUDED */

