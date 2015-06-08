
#ifndef STACK_SIZE_H_INCLUDED
#define STACK_SIZE_H_INCLUDED

#include "stack/stack.h"

/*@
    requires Valid(s);

    assigns \nothing;

    ensures \result == Size(s);
*/
size_type stack_size(const Stack* s);

#endif /* STACK_SIZE_H_INCLUDED */

