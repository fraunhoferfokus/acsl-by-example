
#ifndef STACKSEPARATED_SPEC_INCLUDED
#define STACKSEPARATED_SPEC_INCLUDED

#include "stack.h"

/*@
   predicate
     Separated(Stack* s, Stack* t) =
       \separated(s, s->obj + (0..s->capacity-1),
                  t, t->obj + (0..t->capacity-1));
*/

#endif /* STACKSEPARATED_SPEC_INCLUDED */

