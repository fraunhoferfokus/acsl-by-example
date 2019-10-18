
#include <iostream>
#include <cassert>

#include "stack_pop.h"
#include "stack_init.h"
#include "stack_push.h"
#include "stack_empty.h"

int
main(int argc, char** argv)
{
  Stack a;
  value_type storage[4];
  stack_init(&a, storage, 4);

  stack_push(&a, 14);
  stack_pop(&a);
  assert(stack_empty(&a));

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

