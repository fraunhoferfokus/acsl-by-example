
#include "stack_pop.h"
#include "stack_push.h"
#include "stack_top.h"

/*@
  requires  valid:     \valid(s) && StackInvariant(s);
  requires  not_empty: !StackEmpty(s);
  assigns              s->size, s->obj[s->size-1];
  ensures   equal:     StackEqual{Old,Here}(s, s);
*/
void
axiom_push_of_pop_top(Stack* s)
{
  const value_type val = stack_top(s);
  stack_pop(s);
  stack_push(s, val);
}

