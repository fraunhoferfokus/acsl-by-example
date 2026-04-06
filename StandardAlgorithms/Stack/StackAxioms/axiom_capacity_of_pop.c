
#include "stack_pop.h"
#include "stack_capacity.h"

/*@
  requires   valid:    StackValid(s);
  requires   empty:    !StackEmpty(s);

  ensures    capacity: \result == StackCapacity{Old}(s);
  ensures    valid:    StackValid(s);
*/
size_type axiom_capacity_of_pop(Stack* s)
{
  stack_pop(s);
  return stack_capacity(s);
}

