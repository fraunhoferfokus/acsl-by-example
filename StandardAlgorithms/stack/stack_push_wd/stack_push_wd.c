#include "stack/stack.h"

/*@
  requires Valid(s) && Valid(t);
  requires Equal{Here,Here}(s, t);
  requires !Full(s) && !Full(t);
  requires Separated(s, t);

  ensures Valid(s) && Valid(t);
  ensures Equal{Here,Here}(s, t);
*/
void stack_push_wd(Stack* s, Stack* t, value_type v)
{
  stack_push(s, v);
  stack_push(t, v);
}

