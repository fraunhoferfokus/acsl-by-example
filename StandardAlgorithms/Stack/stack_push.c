
#include "stack_push.h"
#include "stack_full.h"

void stack_push(Stack* s, value_type v)
{
  if (!stack_full(s)) {
    s->data[s->sz++] = v;
  }
}

