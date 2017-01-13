
#ifndef RANDOM_SHUFFLE_H_INCLUDED
#define RANDOM_SHUFFLE_H_INCLUDED

#include "MultisetUnchanged.h"

/*@
  requires \valid(a + (0..n-1));

  assigns a[0..n-1];

  ensures  MultisetUnchanged{Here,Old}(a,n);
*/
void random_shuffle(value_type* a, size_type n);

#endif /* RANDOM_SHUFFLE_H_INCLUDED */

