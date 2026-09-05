
#include <cassert>
#include <cstdlib>
#include <vector>

#include "stack_equal.h"
#include "stack_test.hpp"

// StackEqual is observational: two stacks are equal when they hold the same
// elements, whatever their capacities are and whatever lies in the unused
// part of their storage.
int main(int, char**)
{
  for (const size_type capacity : test_capacities()) {
    std::vector<value_type> storage(capacity, -1);
    std::vector<value_type> other_storage(capacity + 5, 7);

    Stack s;
    Stack t;
    stack_init(&s, storage.data(), capacity);
    stack_init(&t, other_storage.data(), capacity + 5);

    assert(stack_equal(&s, &t));      // both empty, different capacities
    assert(stack_equal(&s, &s));

    for (size_type i = 1; i <= capacity; ++i) {
      const value_type v = static_cast<value_type>(i);

      stack_push(&s, v);
      assert(!stack_equal(&s, &t));   // one element more

      stack_push(&t, v);
      assert(stack_equal(&s, &t));    // the same elements again
    }

    // The same size but a different top.
    stack_pop(&t);
    stack_push(&t, 99);
    assert(!stack_equal(&s, &t));
  }

  return EXIT_SUCCESS;
}
