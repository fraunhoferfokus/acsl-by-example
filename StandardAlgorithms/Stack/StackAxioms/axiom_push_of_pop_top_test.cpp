
#include <cassert>
#include <cstdlib>

#include "stack_functions.h"

extern void axiom_push_of_pop_top(Stack* s);

// Contract: StackEqual{Old,Here}(s, s) -- popping the top and pushing it back
// leaves the stack observationally unchanged. A twin stack is the witness.
void test_push_of_pop_top(size_type pushes)
{
  Stack s;
  Stack twin;
  value_type storage[8];
  value_type twin_storage[8];
  stack_init(&s, storage, 8);
  stack_init(&twin, twin_storage, 8);

  for (size_type i = 0; i < pushes; ++i) {
    const value_type x = static_cast<value_type>(i + 1);
    stack_push(&s, x);
    stack_push(&twin, x);
  }

  assert(stack_equal(&s, &twin));
  assert(!stack_empty(&s));

  axiom_push_of_pop_top(&s);

  assert(stack_equal(&s, &twin));
  assert(stack_top(&s) == stack_top(&twin));

  return;
}

int main(int, char**)
{
  test_push_of_pop_top(1);
  test_push_of_pop_top(4);
  test_push_of_pop_top(8);   // on the full stack

  return EXIT_SUCCESS;
}
