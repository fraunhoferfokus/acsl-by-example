
#include <cassert>
#include <cstdlib>

#include "stack_functions.h"

extern void axiom_pop_of_push(Stack* s, value_type v);

// Contract: StackEqual{Old,Here}(s, s) -- a push followed by a pop leaves the
// stack observationally unchanged. A twin stack, untouched, is the witness.
void test_pop_of_push(size_type pushes, value_type v)
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
  assert(!stack_full(&s));

  axiom_pop_of_push(&s, v);

  assert(stack_equal(&s, &twin));
  assert(stack_size(&s) == pushes);

  return;
}

int main(int, char**)
{
  test_pop_of_push(0, 42);   // on the empty stack
  test_pop_of_push(1, 42);
  test_pop_of_push(7, 42);   // one slot left
  test_pop_of_push(3, -1);

  return EXIT_SUCCESS;
}
