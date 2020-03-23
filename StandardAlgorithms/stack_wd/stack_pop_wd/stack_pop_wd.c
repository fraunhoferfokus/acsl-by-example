
#include "stack_pop.h"

/*@
  requires valid:  \valid(s) && StackInvariant(s);
  requires valid:  \valid(t) && StackInvariant(t);
  requires equal:  StackEqual{Here,Here}(s, t);
  requires sep:    StackSeparated(s, t);
  assigns          s->size;
  assigns          t->size;
  ensures valid:   StackInvariant(s);
  ensures valid:   StackInvariant(t);
  ensures equal:   StackEqual{Here,Here}(s, t);
*/
void
stack_pop_wd(Stack* s, Stack* t)
{
  stack_pop(s);
  stack_pop(t);
}

