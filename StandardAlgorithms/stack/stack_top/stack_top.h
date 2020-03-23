
#ifndef STACK_TOP_H_INCLUDED
#define STACK_TOP_H_INCLUDED

#include "Stack.spec"

/*@
    requires valid: \valid(s) && StackInvariant(s);
    assigns         \nothing;
    ensures  top:   !StackEmpty(s) ==> \result == StackTop(s);
*/
value_type
stack_top(const Stack* s);

#endif /* STACK_TOP_H_INCLUDED */

