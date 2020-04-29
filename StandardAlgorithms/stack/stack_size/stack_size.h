
#ifndef STACK_SIZE_H_INCLUDED
#define STACK_SIZE_H_INCLUDED

#include "Stack.acsl"

/*@
    requires valid: \valid(s) && StackInvariant(s);
    assigns         \nothing;
    ensures  size:  \result == StackSize(s);
*/
size_type
stack_size(const Stack* s);

#endif /* STACK_SIZE_H_INCLUDED */

