
#ifndef STACK_EMPTY_H_INCLUDED
#define STACK_EMPTY_H_INCLUDED

#include "StackObservers.acsl"

/*@
  requires   valid:      StackValid(s);
  terminates             \true;
  exits                  \false;
  assigns                \nothing;
  ensures    empty:      \result == true   <==>  StackEmpty(s);
  ensures    not_empty:  \result == false  <==> !StackEmpty(s);
*/
bool stack_empty(const Stack* s);

#endif /* STACK_EMPTY_H_INCLUDED */

