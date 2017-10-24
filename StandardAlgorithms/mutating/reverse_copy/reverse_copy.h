
#ifndef REVERSE_COPY_H_INCLUDED
#define REVERSE_COPY_H_INCLUDED

#include "ReverseLogic.h"
#include "Unchanged.h"

/*@
  requires valid:  \valid_read(a + (0..n-1));
  requires valid:       \valid(b + (0..n-1));
  requires sep:     \separated(a + (0..n-1), b + (0..n-1));

  assigns b[0..(n-1)];

  ensures reverse:     Reverse{Old,Here}(a, n, b);
  ensures unchanged: Unchanged{Old,Here}(a, n);
*/
void reverse_copy(const value_type* a, size_type n, value_type* b);

#endif /* REVERSE_COPY_H_INCLUDED */
