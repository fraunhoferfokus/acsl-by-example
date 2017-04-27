
#ifndef STACKVALID_H_INCLUDED
#define STACKVALID_H_INCLUDED

#include "StackCapacitySizeTop.h"

/*@ 
  predicate
    Invariant{L}(Stack* s) =
      0 < Capacity(s) &&
      0 <= Size(s) <= Capacity(s) &&
      \valid(Storage(s) + (0..Capacity(s)-1)) &&
      \separated(s, Storage(s) + (0..Capacity(s)-1));
*/ 

#endif /* STACKVALID_H_INCLUDED */

