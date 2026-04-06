
#include "stack_equal.h"
#include "equal.h"

bool stack_equal(const Stack* s, const Stack* t)
{
  return (s->sz == t->sz) && equal(s->data, s->sz, t->data);
}

