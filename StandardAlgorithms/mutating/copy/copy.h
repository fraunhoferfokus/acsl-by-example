
#ifndef COPY_H_INCLUDED
#define COPY_H_INCLUDED

#include "Equal.acsl"

/*@
  requires valid:  \valid_read(a + (0..n-1));
  requires valid:  \valid(b + (0..n-1));
  requires sep:    \separated(a + (0..n-1), b);
  assigns          b[0..n-1];
  ensures equal:   Equal{Old,Here}(a, n, b);
*/
void
copy(const value_type* a, const size_type n, value_type* b);

#endif /* COPY_H_INCLUDED */

