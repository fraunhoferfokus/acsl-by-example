
#include "stack_empty.h"

/*@
  requires valid:  \valid(s) && StackInvariant(s);
  requires valid:  \valid(t) && StackInvariant(t);
  requires equal:  StackEqual{Here,Here}(s, t);
  assigns          \nothing;
  ensures  equal:  \result;
*/
bool
stack_empty_wd(const Stack* s, const Stack* t)
{
  return stack_empty(s) == stack_empty(t);
}

