
#ifndef ROTATE_H_INCLUDED
#define ROTATE_H_INCLUDED

#include "Rotate.acsl"

/*@
  requires   valid:   \valid(a + (0..n-1));
  requires   bound:   p <= n;

  terminates          \true;
  exits               \false;
  assigns             a[0..n-1];

  ensures    result:  \result == n-p;
  ensures    rotate:  Rotate{Old,Here}(a, p, n);
*/
size_type rotate(value_type* a, size_type p, size_type n);

#endif  /* ROTATE_H_INCLUDED */

