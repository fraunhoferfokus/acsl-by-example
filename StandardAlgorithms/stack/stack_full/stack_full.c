
#include "stack_full.h"
#include "stack_size.h"

bool
stack_full(const Stack* s)
{
  return stack_size(s) == s->capacity;
}

