
#ifndef STACK_TOP_H_INCLUDED
#define STACK_TOP_H_INCLUDED

#include "StackObservers.acsl"

/*@
  requires   valid:  StackValid(s);
  terminates         \true;
  exits              \false;
  assigns            \nothing;
  ensures    top:    !StackEmpty(s) ==> \result == StackTop(s);
*/
value_type stack_top(const Stack* s);

#endif /* STACK_TOP_H_INCLUDED */

