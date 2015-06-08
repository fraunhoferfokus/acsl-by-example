
#ifndef REVERSE_COPY_H_INCLUDED
#define REVERSE_COPY_H_INCLUDED

#include "Reversed.h"

/*@
  requires valid_a: \valid_read(a + (0..n-1));
  requires valid_b:      \valid(b + (0..n-1));
  requires sep:      \separated(a + (0..n-1), b + (0..n-1));

  assigns b[0..(n-1)];

  ensures reverse:  Reversed{Here,Here}(a, n, b);
*/
void reverse_copy(const value_type* a, size_type n, value_type* b);

#endif /* REVERSE_COPY_H_INCLUDED */
