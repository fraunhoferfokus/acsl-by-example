
#include "stack_pop.h"
#include "stack_size.h"

/*@
  requires   valid:  StackValid(s);
  requires   empty:  !StackEmpty(s);

  ensures    size:   \result == StackSize{Old}(s) - 1;
  ensures    valid:  StackValid(s);
*/
size_type axiom_size_of_pop(Stack* s)
{
  stack_pop(s);
  return stack_size(s);
}

