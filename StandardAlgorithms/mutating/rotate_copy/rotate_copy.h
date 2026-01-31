
#ifndef ROTATE_COPY_H_INCLUDED
#define ROTATE_COPY_H_INCLUDED

#include "Rotate.acsl"
#include "Unchanged.acsl"

/*@
  requires   bound:      0 <= p <= n;
  requires   valid:      \valid_read(a + (0..n-1));
  requires   valid:      \valid(b + (0..n-1));
  requires   sep:        \separated(a + (0..n-1), b + (0..n-1));

  terminates             \true;
  exits                  \false;
  assigns                b[0..(n-1)];

  ensures    rotate:     Rotate{Old,Here}(a, p, n, b);
  ensures    unchanged:  Unchanged{Old,Here}(a, n);
*/
void
rotate_copy(const value_type* a, size_type p, size_type n, value_type* b);

#endif /* ROTATE_COPY_H_INCLUDED */

