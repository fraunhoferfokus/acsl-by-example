
#include <cassert>
#include <cstdlib>
#include <vector>

#include "stack_functions.h"
#include "stack_empty.h"

int main(int, char**)
{
  std::vector<value_type> storage1(10);
  std::vector<value_type> storage2(3);

  Stack s1, s2;
  stack_init(&s1, storage1.data(), storage1.size());
  stack_init(&s2, storage2.data(), storage2.size());

  // Different capacities.
  assert(s1.cap != s2.cap);

  // Equal (empty) stacks.
  assert(stack_equal(&s1, &s2));

  // Well-definedness: equal stacks -> same empty result.
  assert(stack_empty(&s1) == stack_empty(&s2));
  assert(stack_empty(&s1));

  // Push identical sequence within smaller capacity.
  stack_push(&s1, 1);
  stack_push(&s2, 1);

  stack_push(&s1, 2);
  stack_push(&s2, 2);

  // Still equal, still different capacities.
  assert(stack_equal(&s1, &s2));
  assert(s1.cap != s2.cap);

  // Well-definedness again.
  assert(stack_empty(&s1) == stack_empty(&s2));
  assert(!stack_empty(&s1));

  // Make sizes differ but keep same prefix.
  stack_push(&s1, 3);

  assert(!stack_equal(&s1, &s2));

  // No requirement here, but sanity check:
  assert(stack_empty(&s1) == false);
  assert(stack_empty(&s2) == false);

  return EXIT_SUCCESS;
}
