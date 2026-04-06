
#include <cassert>
#include <cstdlib>
#include <vector>

#include "stack_functions.h"

int main(int, char**)
{
  std::vector<value_type> storage1(10);
  std::vector<value_type> storage2(6);

  Stack s1, s2;
  stack_init(&s1, storage1.data(), storage1.size());
  stack_init(&s2, storage2.data(), storage2.size());

  // Equal (empty) => sizes equal.
  assert(stack_equal(&s1, &s2));
  assert(stack_size(&s1) == stack_size(&s2));

  // Equal (one element) => sizes equal.
  stack_push(&s1, 4);
  stack_push(&s2, 4);
  assert(stack_equal(&s1, &s2));
  assert(stack_size(&s1) == stack_size(&s2));

  // Same prefix, different size => must NOT be equal.
  stack_push(&s1, 7);
  assert(stack_size(&s1) != stack_size(&s2));
  assert(!stack_equal(&s1, &s2));

  // Restore equality => sizes equal again.
  stack_push(&s2, 7);
  assert(stack_equal(&s1, &s2));
  assert(stack_size(&s1) == stack_size(&s2));

  return EXIT_SUCCESS;
}

