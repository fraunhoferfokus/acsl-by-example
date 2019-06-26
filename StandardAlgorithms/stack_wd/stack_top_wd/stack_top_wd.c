
#include "stack/stack.h"

/*@
  requires valid: \valid(s) && Invariant(s) && !Empty(s);
  requires valid: \valid(t) && Invariant(t) && !Empty(t);
  requires equal: Equal{Here,Here}(s, t);

  assigns \nothing;

  ensures equal:  \result;
*/
bool
stack_top_wd(const Stack* s, const Stack* t)
{
  return stack_top(s) == stack_top(t);
}

