
#include "StackLogic.spec"
#include "stack_empty.h"
#include "stack_size.h"

bool
stack_empty(const Stack* s)
{
  return stack_size(s) == 0u;
}

