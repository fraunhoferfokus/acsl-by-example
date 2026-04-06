
#ifndef STACK_FULL_H_INCLUDED
#define STACK_FULL_H_INCLUDED

#include "StackObservers.acsl"

/*@
  requires   valid:     StackValid(s);
  terminates            \true;
  exits                 \false;
  assigns               \nothing;
  ensures    full:      \result == \true   <==>   StackFull(s);
  ensures    not_full:  \result == \false  <==>  !StackFull(s);
*/
bool stack_full(const Stack* s);

#endif /* STACK_FULL_H_INCLUDED */

