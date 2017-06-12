
#include "stack/stack.h"

/*@
  requires valid: \valid(s) && Invariant(s);
  requires valid: \valid(t) && Invariant(t);
  requires equal: Equal{Here,Here}(s, t);

  assigns \nothing;

  ensures equal:  \result;
*/
bool stack_size_wd(const Stack* s, const Stack* t)
{
  return stack_size(s) == stack_size(t);
}

