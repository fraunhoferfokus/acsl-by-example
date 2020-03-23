
#include "stack_top.h"

/*@
  requires valid:  \valid(s) && StackInvariant(s) && !StackEmpty(s);
  requires valid:  \valid(t) && StackInvariant(t) && !StackEmpty(t);
  requires equal:  StackEqual{Here,Here}(s, t);
  assigns          \nothing;
  ensures  equal:  \result;
*/
bool
stack_top_wd(const Stack* s, const Stack* t)
{
  return stack_top(s) == stack_top(t);
}

