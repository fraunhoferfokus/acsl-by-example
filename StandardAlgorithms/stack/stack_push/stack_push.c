
#include "stack/stack.h"

void stack_push(Stack* s, value_type v)
{
  if (!stack_full(s))
  {
    s->obj[s->size++] = v;
  }
}

