
#include "stack/stack.h"

/*@
  requires Valid(s);
  requires Valid(t);
  requires Equal{Here,Here}(s, t);
  requires Separated(s, t);

  assigns s->size;
  assigns t->size;

  ensures Valid(s);
  ensures Valid(t);
  ensures Equal{Here,Here}(s, t);
*/
void stack_pop_wd(Stack* s, Stack* t)
{
  stack_pop(s);
  stack_pop(t);
}

