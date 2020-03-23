
#include "stack_size.h"

/*@
  requires valid:  \valid(s) && StackInvariant(s);
  requires valid:  \valid(t) && StackInvariant(t);
  requires equal:  StackEqual{Here,Here}(s, t);
  assigns          \nothing;
  ensures  equal:  \result;
*/
bool
stack_size_wd(const Stack* s, const Stack* t)
{
  return stack_size(s) == stack_size(t);
}

