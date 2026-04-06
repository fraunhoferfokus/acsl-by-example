
#ifndef STACK_CAPACITY_H_INCLUDED
#define STACK_CAPACITY_H_INCLUDED

#include "StackObservers.acsl"

/*@
  requires   valid:    StackValid(s);
  terminates           \true;
  exits                \false;
  assigns              \nothing;
  ensures    capacity: \result == StackCapacity(s);
*/
size_type stack_capacity(const Stack* s);

#endif /* STACK_CAPACITY_H_INCLUDED */

