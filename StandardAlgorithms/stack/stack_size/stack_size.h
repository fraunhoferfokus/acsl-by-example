
#ifndef STACK_SIZE_H_INCLUDED
#define STACK_SIZE_H_INCLUDED

#include "StackLogic.spec"

/*@
    requires valid: \valid(s) && Invariant(s);

    assigns \nothing;

    ensures size: \result == Size(s);
*/
size_type
stack_size(const Stack* s);

#endif /* STACK_SIZE_H_INCLUDED */

