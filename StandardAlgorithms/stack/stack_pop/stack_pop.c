
#include "stack_pop.h"
#include "stack_empty.h"

void
stack_pop(Stack* s)
{
  if (!stack_empty(s)) {
    --s->size;
  }
}

