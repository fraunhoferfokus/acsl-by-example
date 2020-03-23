
#include "stack_pop.h"
#include "stack_push.h"

/*@
  requires  valid:    \valid(s) && StackInvariant(s);
  requires  not_full: !StackFull(s);
  assigns             s->size, s->obj[s->size];
  ensures   equal:    StackEqual{Old,Here}(s, s);
*/
void
axiom_pop_of_push(Stack* s, value_type v)
{
  stack_push(s, v);
  stack_pop(s);
}

