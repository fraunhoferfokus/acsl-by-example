
#ifndef STACK_EMPTY_H_INCLUDED
#define STACK_EMPTY_H_INCLUDED

#include "Stack.acsl"

/*@
  requires   valid:      \valid(s) && StackInvariant(s);

  terminates             \true;
  exits                  \false;
  assigns                \nothing;

  ensures    empty:      \result == 1  <==>  StackEmpty(s);
  ensures    not_empty:  \result == 0  <==> !StackEmpty(s);
*/
bool
stack_empty(const Stack* s);

#endif /* STACK_EMPTY_H_INCLUDED */

