
#ifndef STACKEMPTYFULL_SPEC_INCLUDED
#define STACKEMPTYFULL_SPEC_INCLUDED

#include "StackCapacitySizeTop.spec"

/*@
  predicate
    Empty{L}(Stack* s) =  Size(s) == 0;

  predicate
    Full{L}(Stack* s)  =  Size(s) == Capacity(s);
*/

#endif /* STACKEMPTYFULL_SPEC_INCLUDED */

