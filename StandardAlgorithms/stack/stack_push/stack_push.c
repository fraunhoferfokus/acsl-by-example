
#include "stack/stack.h"

void
stack_push(Stack* s, value_type v)
{
  if (!stack_full(s)) {
    //@ assert not_full: s->size < s->capacity;
    s->obj[s->size++] = v;
  }
}

