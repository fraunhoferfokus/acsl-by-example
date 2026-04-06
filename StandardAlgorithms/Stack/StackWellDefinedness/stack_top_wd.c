
#include "stack_top.h"

/*@
  requires   valid:      StackValid(s) &&  StackValid(t);
  requires   not_empty: !StackEmpty(s) && !StackEmpty(t);
  requires   equal:      StackEqual{Here,Here}(s, t);

  ensures    equal:     \result == true;
*/
bool stack_top_wd(const Stack* s, const Stack* t)
{
  return stack_top(s) == stack_top(t);
}

