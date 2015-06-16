
#include "stack/stack.h"

/*@
  requires Valid(s) && !Empty(s);
  requires Valid(t) && !Empty(t);
  requires Equal{Here,Here}(s, t);

  assigns \nothing;

  ensures \result;
*/
bool stack_top_wd(const Stack* s, const Stack* t)
{
  return stack_top(s) == stack_top(t);
}

