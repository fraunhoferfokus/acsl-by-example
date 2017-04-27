
#include "stack/stack.h"

/*@
  requires  valid:    \valid(s) && Invariant(s);
  requires  not_full: !Full(s);

  assigns   s->size;
  assigns   s->obj[s->size];

  ensures   equal:    Equal{Pre,Here}(s, s);
*/
void axiom_pop_of_push(Stack* s, value_type v)
{
  stack_push(s, v);
  stack_pop(s);
}

