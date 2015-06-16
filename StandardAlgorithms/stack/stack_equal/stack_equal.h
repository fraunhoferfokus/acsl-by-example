
#ifndef STACK_EQUAL_H_INCLUDED
#define STACK_EQUAL_H_INCLUDED

#include "stack/stack.h"

/*@
    requires Valid(s);
    requires Valid(t);

    assigns \nothing;

    ensures \result == 1  <==>  Equal{Here,Here}(s, t);
    ensures \result == 0  <==> !Equal{Here,Here}(s, t);
*/
bool stack_equal(const Stack* s, const Stack* t);

#endif /* STACK_EQUAL_H_INCLUDED */

