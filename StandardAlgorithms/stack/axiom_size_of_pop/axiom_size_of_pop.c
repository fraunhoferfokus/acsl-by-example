
#include "stack/stack.h"

/*@
  requires  Valid(s) && !Empty(s);
  assigns   s->size;
  ensures   \result == Size{Old}(s) - 1;
*/
size_type axiom_size_of_pop(Stack* s)
{
  stack_pop(s);
  return stack_size(s);
}

