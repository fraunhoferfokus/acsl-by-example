
#include "StackLogic.spec"
#include "stack_pop.h"
#include "stack_size.h"

/*@
  requires valid:  \valid(s) && Invariant(s);
  requires empty:  !Empty(s);
  assigns          s->size;
  ensures   size:  \result == Size{Old}(s) - 1;
*/
size_type
axiom_size_of_pop(Stack* s)
{
  stack_pop(s);
  return stack_size(s);
}

