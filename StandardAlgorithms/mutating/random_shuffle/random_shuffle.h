
#ifndef RANDOM_SHUFFLE_H_INCLUDED
#define RANDOM_SHUFFLE_H_INCLUDED

#include "MultisetUnchanged.h"

extern unsigned short random_seed[3];

/*@
  requires \valid(a + (0..n-1));

  assigns a[0..n-1];
  assigns random_seed[0..2];

  ensures  MultisetUnchanged{Old,Here}(a,n);
*/
void random_shuffle(value_type* a, size_type n);

#endif /* RANDOM_SHUFFLE_H_INCLUDED */

