
#ifndef STACK_EMPTY_H_INCLUDED
#define STACK_EMPTY_H_INCLUDED

#include "stack/stack.h"

/*@
    requires Valid(s);

    assigns \nothing;

    ensures \result == 1 <==>  Empty(s);
    ensures \result == 0 <==> !Empty(s);
*/
bool stack_empty(const Stack* s);

#endif /* STACK_EMPTY_H_INCLUDED */

