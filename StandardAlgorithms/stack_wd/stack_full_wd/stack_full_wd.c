
#include "stack/stack.h"

/*@
  requires valid: \valid(s) && Invariant(s);
  requires valid: \valid(t) && Invariant(t);
  requires equal: Equal{Here,Here}(s, t);

  assigns \nothing;

  ensures equal: \result;
*/
bool stack_full_wd(const Stack* s, const Stack* t)
{
  return stack_full(s) == stack_full(t);
}

