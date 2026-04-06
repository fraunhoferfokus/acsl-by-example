
#include <cassert>
#include <cstdlib>
#include <vector>

#include "stack_functions.h"
#include "stack_full.h"

int main(int, char**)
{
  std::vector<value_type> storage1(2);
  std::vector<value_type> storage2(10);

  Stack s1, s2;
  stack_init(&s1, storage1.data(), storage1.size());
  stack_init(&s2, storage2.data(), storage2.size());
  // Different capacities.
  assert(s1.cap != s2.cap);

  stack_push(&s1, 2);
  stack_push(&s2, 2);
  assert(stack_equal(&s1, &s2));
  assert(!stack_full(&s1));
  assert(!stack_full(&s2));

  stack_push(&s1, 5);
  stack_push(&s2, 5);
  // no well-definedness: equal stacks -> not the same full result.
  assert(stack_equal(&s1, &s2));
  assert(stack_full(&s1));
  assert(!stack_full(&s2));

  return EXIT_SUCCESS;
}
