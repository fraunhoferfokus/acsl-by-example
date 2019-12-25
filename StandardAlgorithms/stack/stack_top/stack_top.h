
#ifndef STACK_TOP_H_INCLUDED
#define STACK_TOP_H_INCLUDED

#include "StackLogic.spec"

/*@
    requires valid: \valid(s) && Invariant(s);
    assigns         \nothing;
    ensures  top:   !Empty(s) ==> \result == Top(s);
*/
value_type
stack_top(const Stack* s);

#endif /* STACK_TOP_H_INCLUDED */

