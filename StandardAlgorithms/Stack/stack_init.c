
#include "stack_init.h"

void stack_init(Stack* s, value_type* data, size_type cap)
{
  s->data  = data;
  s->cap   = cap;
  s->sz    = 0u;
}

