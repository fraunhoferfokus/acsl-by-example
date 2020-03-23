
#include "stack_pop.h"
#include "stack_size.h"

/*@
  requires valid:  \valid(s) && StackInvariant(s);
  requires empty:  !StackEmpty(s);
  assigns          s->size;
  ensures   size:  \result == StackSize{Old}(s) - 1;
*/
size_type
axiom_size_of_pop(Stack* s)
{
  stack_pop(s);
  return stack_size(s);
}

