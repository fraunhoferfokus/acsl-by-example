
#include "stack_push.h"
#include "StackLemmas.acsl"

/*@
  requires valid:     \valid(s) && StackInvariant(s);
  requires valid:     \valid(t) && StackInvariant(t);
  requires equal:     StackEqual{Here,Here}(s, t);
  requires not_full:  !StackFull(s) && !StackFull(t);
  requires sep:       StackSeparated(s, t);
  assigns             s->size, s->obj[s->size];
  assigns             t->size, t->obj[t->size];
  ensures  valid:     StackInvariant(s) && StackInvariant(t);
  ensures  equal:     StackEqual{Here,Here}(s, t);
*/
void
stack_push_wd(Stack* s, Stack* t, value_type v)
{
  stack_push(s, v);
  stack_push(t, v);
  //@ assert top:   StackTop(s) == v;
  //@ assert top:   StackTop(t) == v;
  //@ assert equal: EqualRanges{Here,Here}(StackStorage(s), StackSize{Pre}(s), StackStorage(t));
}

