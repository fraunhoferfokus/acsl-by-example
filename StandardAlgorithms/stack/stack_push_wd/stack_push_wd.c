
#include "stack/stack.h"
#include "StackPushEqual.h"

/*@
  requires valid:     Valid(s) && Valid(t);
  requires equal:     Equal{Here,Here}(s, t);
  requires not_full:  !Full(s) && !Full(t);
  requires separated: Separated(s, t);

  assigns s->size, s->obj[s->size];
  assigns t->size, t->obj[t->size];

  ensures  valid:     Valid(s) && Valid(t);
  ensures  equal:     Equal{Here,Here}(s, t);
*/
void stack_push_wd(Stack* s, Stack* t, value_type v)
{
  stack_push(s, v);
  stack_push(t, v);
  //@ assert top:   Top(s) == v;
  //@ assert top:   Top(t) == v;
  //@ assert equal: EqualRanges{Here,Here}(Storage(s), Size{Pre}(s), Storage(t));
}

