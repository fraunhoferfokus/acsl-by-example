
#ifndef REVERSE_H_INCLUDED
#define REVERSE_H_INCLUDED

#include "ReverseLogic.h"

/*@
  requires valid: \valid(a + (0..n-1));

  assigns a[0..(n-1)];

  ensures reverse: Reverse{Here,Old}(a, n);
*/
void reverse(value_type* a, size_type n);

#endif  /* REVERSE_H_INCLUDED */

