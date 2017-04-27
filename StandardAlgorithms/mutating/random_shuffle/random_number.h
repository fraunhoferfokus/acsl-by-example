
#ifndef RANDOM_NUMBER_H_INCLUDED
#define RANDOM_NUMBER_H_INCLUDED

#include "typedefs.h"

extern unsigned short random_seed[3];

/*@
  requires 0 < n;
  assigns random_seed[0..2];
  ensures 0 <= \result < n;
*/
size_type random_number(size_type n);

#endif /* RANDOM_NUMBER_H_INCLUDED */

