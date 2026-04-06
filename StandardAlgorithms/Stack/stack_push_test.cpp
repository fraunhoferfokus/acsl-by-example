
#include <iostream>
#include <cassert>

#include "stack_push.h"
#include "stack_init.h"
#include "stack_empty.h"

int main(int, char**)
{
  Stack a;
  value_type storage[8];
  stack_init(&a, storage, 8);

  stack_push(&a, 14);
  assert(!stack_empty(&a));

  return EXIT_SUCCESS;
}

