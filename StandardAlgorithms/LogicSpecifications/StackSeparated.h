
#ifndef STACKSEPARATED_H_INCLUDED
#define STACKSEPARATED_H_INCLUDED

#include "stack/stack_definition.h"

/*@
   predicate
     Separated(Stack* s, Stack* t) =
       \separated(s, s->obj + (0..s->capacity-1),
                  t, t->obj + (0..t->capacity-1));
*/ 

#endif /* STACKSEPARATED_H_INCLUDED */

