
#ifndef STACKEQUAL_SPEC_INCLUDED
#define STACKEQUAL_SPEC_INCLUDED

#include "StackCapacitySizeTop.spec"
#include "EqualRanges.spec"

/*@
   predicate
     Equal{S,T}(Stack* s, Stack* t) =
       Size{S}(s) == Size{T}(t) &&
       EqualRanges{S,T}(Storage{S}(s), Size{S}(s), Storage{T}(t));
*/

#endif /* STACKEQUAL_SPEC_INCLUDED */

