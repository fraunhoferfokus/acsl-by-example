
#include <iostream>
#include <cassert>
#include <stack>

#include "stack_full.h"
#include "stack_init.h"

int main(int, char**)
{
  Stack b;
  value_type storage[6];
  stack_init(&b, storage, 6);

  assert(stack_full(&b) == 0);

  return EXIT_SUCCESS;
}

