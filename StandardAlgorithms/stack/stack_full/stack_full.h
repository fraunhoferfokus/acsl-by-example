
#ifndef STACK_FULL_H_INCLUDED
#define STACK_FULL_H_INCLUDED

#include "StackLogic.spec"

/*@
    requires valid: \valid(s) && Invariant(s);

    assigns \nothing;

    ensures full:     \result == 1  <==>  Full(s);
    ensures not_full: \result == 0  <==> !Full(s);
*/
bool
stack_full(const Stack* s);

#endif /* STACK_FULL_H_INCLUDED */

