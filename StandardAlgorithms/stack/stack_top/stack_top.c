
#include "stack/stack.h"

value_type stack_top(const Stack* s)
{
  if (!stack_empty(s))
  {
    return s->obj[s->size - 1];
  }
  else
  {
    return s->obj[0];
  }
}

