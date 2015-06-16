
#include "stack_full.h"

bool stack_full(const Stack* s)
{
  return stack_size(s) == s->capacity;
}

