
#include "StackLogic.spec"
#include "stack_equal.h"
#include "equal.h"

bool
stack_equal(const Stack* s, const Stack* t)
{
  return (s->size == t->size) && equal(s->obj, s->size, t->obj);
}

