
#ifndef REVERSE_H_INCLUDED
#define REVERSE_H_INCLUDED

#include "Reversed.h"
#include "Unchanged.h"

/*@
  requires valid: \valid(a + (0..n-1));

  assigns a[0..(n-1)];

  ensures reverse: Reversed{Here,Old}(a, n, a);
*/
void reverse(value_type* a, size_type n);

#endif  /* REVERSE_H_INCLUDED */

