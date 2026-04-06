
#ifndef STACK_EQUAL_H_INCLUDED
#define STACK_EQUAL_H_INCLUDED

#include "StackEqual.acsl"
#include "StackInvariant.acsl"

/*@
  requires   valid:      StackValid(s) && StackValid(t);
  terminates             \true;
  exits                  \false;
  assigns                \nothing;
  ensures    equal:      \result == true   <==>  StackEqual{Here,Here}(s, t);
  ensures    not_equal:  \result == false  <==> !StackEqual{Here,Here}(s, t);
*/
bool stack_equal(const Stack* s, const Stack* t);

#endif /* STACK_EQUAL_H_INCLUDED */

