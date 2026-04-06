
#include "stack_push.h"
#include "stack_capacity.h"

/*@
  requires   valid:     StackValid(s);
  requires   not_full:  !StackFull(s);

  ensures    capacity:  \result == \old(StackCapacity(s));
  ensures    valid:     StackValid(s);
*/
size_type axiom_capacity_of_push(Stack* s, value_type v)
{
  stack_push(s, v);
  return stack_capacity(s);
}

