
#ifndef STACK_EQUAL_H_INCLUDED
#define STACK_EQUAL_H_INCLUDED

#include "stack/stack.h"

/*@
    requires valid: \valid(s) && Invariant(s);
    requires valid: \valid(t) && Invariant(t);

    assigns \nothing;

    ensures equal:     \result == 1  <==>  Equal{Here,Here}(s, t);
    ensures not_equal: \result == 0  <==> !Equal{Here,Here}(s, t);
*/
bool stack_equal(const Stack* s, const Stack* t);

#endif /* STACK_EQUAL_H_INCLUDED */

