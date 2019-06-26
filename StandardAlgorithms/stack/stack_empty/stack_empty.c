
#include "stack/stack.h"

bool
stack_empty(const Stack* s)
{
  return stack_size(s) == 0u;
}

