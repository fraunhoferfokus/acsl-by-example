
#include <cassert>
#include <cstdlib>
#include <vector>

#include "stack_functions.h"
#include "stack_top.h"

int main(int, char**)
{
  std::vector<value_type> storage1(10);
  std::vector<value_type> storage2(4);

  Stack s1, s2;
  stack_init(&s1, storage1.data(), storage1.size());
  stack_init(&s2, storage2.data(), storage2.size());

  // Different capacities.
  assert(s1.cap != s2.cap);

  // Fill both stacks with the same sequence (within smaller capacity).
  stack_push(&s1, 11);
  stack_push(&s2, 11);

  stack_push(&s1, 22);
  stack_push(&s2, 22);

  stack_push(&s1, 33);
  stack_push(&s2, 33);

  // Preconditions for well-definedness:
  // - both non-empty
  // - observationally equal
  assert(!stack_empty(&s1));
  assert(!stack_empty(&s2));
  assert(stack_equal(&s1, &s2));

  // Well-definedness: equal stacks -> same top element.
  assert(stack_top(&s1) == stack_top(&s2));
  assert(stack_top(&s1) == 33);

  // Change the top of only one stack: equality must break.
  // (This is not required by the WD lemma, but it catches "top ignores sz"
  // or "equal ignores last element" style bugs.)
  stack_pop(&s1);
  stack_push(&s1, 44);

  assert(!stack_equal(&s1, &s2));
  assert(stack_top(&s1) == 44);
  assert(stack_top(&s2) == 33);

  // Restore equality, check WD again.
  stack_pop(&s2);
  stack_push(&s2, 44);

  assert(stack_equal(&s1, &s2));
  assert(stack_top(&s1) == stack_top(&s2));

  return EXIT_SUCCESS;
}

