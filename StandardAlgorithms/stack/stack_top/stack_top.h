
#ifndef STACK_TOP_H_INCLUDED
#define STACK_TOP_H_INCLUDED

#include "stack/stack.h"

/*@
    requires Valid(s);

    assigns \nothing;

    ensures !Empty(s) ==> \result == Top(s);
*/
value_type stack_top(const Stack* s);

#endif /* STACK_TOP_H_INCLUDED */

