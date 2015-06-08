
#include "stack/stack.h"

/*@
  requires Valid(s);
  requires Valid(t);
  requires Equal{Here,Here}(s, t);

  assigns \nothing;

  ensures \result;
*/
bool stack_empty_wd(const Stack* s, const Stack* t)
{
  return stack_empty(s) == stack_empty(t);
}

