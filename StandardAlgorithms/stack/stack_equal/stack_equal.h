
#ifndef STACK_EQUAL_H_INCLUDED
#define STACK_EQUAL_H_INCLUDED

#include "Stack.spec"

/*@
    requires valid:     \valid(s) && StackInvariant(s);
    requires valid:     \valid(t) && StackInvariant(t);
    assigns             \nothing;
    ensures  equal:     \result == 1  <==>  StackEqual{Here,Here}(s, t);
    ensures  not_equal: \result == 0  <==> !StackEqual{Here,Here}(s, t);
*/
bool
stack_equal(const Stack* s, const Stack* t);

#endif /* STACK_EQUAL_H_INCLUDED */

