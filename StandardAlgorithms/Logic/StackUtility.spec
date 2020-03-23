
#ifndef STACKUTILTY_SPEC_INCLUDED
#define STACKUTILTY_SPEC_INCLUDED

#include "StackInvariant.spec"
#include "Unchanged.spec"

/*@
  axiomatic StackUtility
  {
    predicate
    StackSeparated(Stack* s, Stack* t) =
      \separated(s, s->obj + (0..s->capacity-1),
                 t, t->obj + (0..t->capacity-1));

    predicate
    StackUnchanged{K,L}(Stack* s) =
      StackSize{K}(s)     == StackSize{L}(s)      &&
      StackStorage{K}(s)  == StackStorage{L}(s)   &&
      StackCapacity{K}(s) == StackCapacity{L}(s)  &&
      Unchanged{K,L}(StackStorage{K}(s), StackSize{K}(s));
  }
*/

#endif /* STACKUTILTY_SPEC_INCLUDED */

