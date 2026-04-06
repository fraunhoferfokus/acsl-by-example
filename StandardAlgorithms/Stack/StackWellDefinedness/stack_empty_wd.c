
#include "stack_empty.h"

/*@
  requires   valid:  StackValid(s) && StackValid(t);
  requires   equal:  StackEqual{Here,Here}(s, t);

  ensures    equal:  \result == true;
*/
bool stack_empty_wd(const Stack* s, const Stack* t)
{
  return stack_empty(s) == stack_empty(t);
}

