
#include "stack/stack.h"

/*@
  requires  Valid(s) && !Empty(s);
  assigns   s->size, s->obj[s->size-1];
  ensures   Equal{Here,Old}(s, s);
*/
void axiom_push_of_pop_top(Stack* s)
{
  const value_type val = stack_top(s);
  stack_pop(s);
  stack_push(s, val);
}

