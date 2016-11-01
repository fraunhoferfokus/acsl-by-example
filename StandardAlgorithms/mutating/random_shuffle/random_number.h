
#ifndef RANDOM_NUMBER_H_INCLUDED
#define RANDOM_NUMBER_H_INCLUDED

#include "typedefs.h"


/*@
  requires 0 < n;

  assigns \nothing;

  ensures 0 <= \result < n;
*/
size_type random_number(size_type n);

#endif /* RANDOM_NUMBER_H_INCLUDED */

