
#include "StackLogic.spec"
#include "stack_pop.h"

/*@
  requires valid:  \valid(s) && Invariant(s);
  requires valid:  \valid(t) && Invariant(t);
  requires equal:  Equal{Here,Here}(s, t);
  requires sep:    Separated(s, t);
  assigns          s->size;
  assigns          t->size;
  ensures valid:   Invariant(s);
  ensures valid:   Invariant(t);
  ensures equal:   Equal{Here,Here}(s, t);
*/
void
stack_pop_wd(Stack* s, Stack* t)
{
  stack_pop(s);
  stack_pop(t);
}

