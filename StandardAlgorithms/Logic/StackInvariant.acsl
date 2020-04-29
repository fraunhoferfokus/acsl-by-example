
#ifndef STACKINVARIANT_SPEC_INCLUDED
#define STACKINVARIANT_SPEC_INCLUDED

#include "stack.h"

/*@
  axiomatic StackInvariant
  {
    logic integer
    StackCapacity{L}(Stack* s) = s->capacity;

    logic integer
    StackSize{L}(Stack* s) = s->size;

    logic value_type*
    StackStorage{L}(Stack* s) = s->obj;

    logic integer
    StackTop{L}(Stack* s) = s->obj[s->size-1];

    predicate
    StackEmpty{L}(Stack* s) =  StackSize(s) == 0;

    predicate
    StackFull{L}(Stack* s)  =  StackSize(s) == StackCapacity(s);

    predicate
    StackInvariant{L}(Stack* s) =
      0 < StackCapacity(s) &&
      0 <= StackSize(s) <= StackCapacity(s) &&
      \valid(StackStorage(s) + (0..StackCapacity(s)-1)) &&
      \separated(s, StackStorage(s) + (0..StackCapacity(s)-1));
  }
*/

#endif /* STACKINVARIANT_SPEC_INCLUDED */

