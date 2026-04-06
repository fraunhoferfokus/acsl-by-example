
#include "stack_pop.h"
#include "stack_push.h"

/*@
  requires   valid:     StackValid(s);
  requires   not_full:  !StackFull(s);

  ensures    equal:     StackEqual{Old,Here}(s, s);
  ensures    valid:     StackValid(s);
*/
void axiom_pop_of_push(Stack* s, value_type v)
{
  stack_push(s, v);
  stack_pop(s);
}

