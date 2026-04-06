
#include "stack_pop.h"
#include "stack_push.h"
#include "stack_top.h"

/*@
  requires   valid:      StackValid(s);
  requires   not_empty:  !StackEmpty(s);

  ensures    equal:      StackEqual{Old,Here}(s, s);
  ensures    valid:      StackValid(s);
*/
void axiom_push_of_pop_top(Stack* s)
{
  const value_type v = stack_top(s);
  stack_pop(s);
  stack_push(s, v);
}

