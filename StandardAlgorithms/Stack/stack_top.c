
#include "stack_top.h"
#include "stack_empty.h"

value_type stack_top(const Stack* s)
{
  if (!stack_empty(s)) {
    return s->data[s->sz - 1u];
  }
  else {
    return s->data[0u];
  }
}

