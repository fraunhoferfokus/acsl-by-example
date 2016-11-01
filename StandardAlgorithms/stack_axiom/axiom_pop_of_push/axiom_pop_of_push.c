
#include "stack/stack.h"

/*@
  requires  Valid(s) && !Full(s);
  assigns   s->size, s->obj[s->size];
  ensures   Equal{Pre,Here}(s, s);
*/
void axiom_pop_of_push(Stack* s, value_type v)
{
  stack_push(s, v);
  stack_pop(s);
}

