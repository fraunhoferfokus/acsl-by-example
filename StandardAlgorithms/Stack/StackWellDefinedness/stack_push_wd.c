
#include "stack_push.h"
#include "StackSeparated.acsl"

/*@
  requires   valid:     StackValid(s) && StackValid(t);
  requires   equal:     StackEqual{Here,Here}(s, t);
  requires   not_full:  !StackFull(s) && !StackFull(t);
  requires   sep:       StackSeparated(s, t);

  ensures    valid:     StackValid(s) && StackValid(t);
  ensures    equal:     StackEqual{Here,Here}(s, t);
*/
void stack_push_wd(Stack* s, Stack* t, value_type v)
{
  stack_push(s, v);
  stack_push(t, v);
}

