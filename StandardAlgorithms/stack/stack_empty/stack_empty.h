
#ifndef STACK_EMPTY_H_INCLUDED
#define STACK_EMPTY_H_INCLUDED

#include "StackLogic.spec"

/*@
    requires valid: \valid(s) && Invariant(s);

    assigns \nothing;

    ensures empty:     \result == 1  <==>  Empty(s);
    ensures not_empty: \result == 0  <==> !Empty(s);
*/
bool
stack_empty(const Stack* s);

#endif /* STACK_EMPTY_H_INCLUDED */

