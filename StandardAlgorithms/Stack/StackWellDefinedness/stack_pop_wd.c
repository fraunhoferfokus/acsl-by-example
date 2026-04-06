
#include "stack_pop.h"
#include "StackSeparated.acsl"

/*@
  requires   valid:  StackValid(s) && StackValid(t);
  requires   equal:  StackEqual{Here,Here}(s, t);
  requires   sep:    StackSeparated(s, t);

  ensures    valid:  StackValid(s) && StackValid(t);
  ensures    equal:  StackEqual{Here,Here}(s, t);
*/
void stack_pop_wd(Stack* s, Stack* t)
{
  stack_pop(s);
  stack_pop(t);
}

