
#include "stack/stack.h"

void stack_pop(Stack* s)
{
  if (!stack_empty(s))
  {
    --s->size;
  }
}

