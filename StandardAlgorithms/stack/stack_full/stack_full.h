
#ifndef STACK_FULL_H_INCLUDED
#define STACK_FULL_H_INCLUDED

#include "stack/stack.h"

/*@
    requires Valid(s);

    assigns \nothing;

    ensures \result == 1 <==>  Full(s);
    ensures \result == 0 <==> !Full(s);
*/
bool stack_full(const Stack* s);

#endif /* STACK_FULL_H_INCLUDED */

