
#ifndef STACKEQUAL_H_INCLUDED
#define STACKEQUAL_H_INCLUDED

#include "StackCapacitySizeTop.h"
#include "EqualRanges.h"

/*@
   predicate
     Equal{S,T}(Stack* s, Stack* t) =
       Size{S}(s) == Size{T}(t) &&
       EqualRanges{S,T}(Storage{S}(s), Size{S}(s), Storage{T}(t));
*/ 

#endif /* STACKEQUAL_H_INCLUDED */

