
#include "stack_size.h"

/*@
  requires   valid:  StackValid(s) && StackValid(t);
  requires   equal:  StackEqual{Here,Here}(s, t);

  ensures    equal:  \result == true;
*/
bool stack_size_wd(const Stack* s, const Stack* t)
{
  return stack_size(s) == stack_size(t);
}

