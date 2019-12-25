
#ifndef RANDOM_NUMBER_H_INCLUDED
#define RANDOM_NUMBER_H_INCLUDED

#include "typedefs.h"

/*@
  requires  pos:    0 < n;
  requires  valid:  \valid(state + (0..2));
  assigns           state[0..2];
  ensures   result: 0 <= \result < n;
*/
size_type
random_number(unsigned short* state, size_type n);


/*@
  requires  \valid(state + (0..2));

  assigns   state[0..2];
*/
void
random_init(unsigned short* state);

#endif /* RANDOM_NUMBER_H_INCLUDED */

