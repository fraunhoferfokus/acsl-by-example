
#include <cassert>
#include <cstdlib>

#include "stack_functions.h"

extern size_type axiom_size_of_push(Stack* s, value_type v);

// Contract: \result == \old(StackSize(s)) + 1.
int main(int, char**)
{
  Stack s;
  value_type storage[8];
  stack_init(&s, storage, 8);

  // From empty up to full, one push at a time.
  for (size_type expected = 1; expected <= 8; ++expected) {
    const size_type before = stack_size(&s);
    assert(!stack_full(&s));
    assert(axiom_size_of_push(&s, static_cast<value_type>(expected)) == before + 1);
    assert(stack_size(&s) == expected);
    assert(stack_top(&s) == static_cast<value_type>(expected));
  }

  assert(stack_full(&s));

  return EXIT_SUCCESS;
}
