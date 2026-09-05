
#include <cassert>
#include <cstdlib>
#include <stack>
#include <vector>

#include "stack_push.h"
#include "stack_test.hpp"

// Every push must add its value on top and leave the rest of the stack
// alone, up to the capacity the contract allows.
int main(int, char**)
{
  for (const size_type capacity : test_capacities()) {
    std::vector<value_type> storage(capacity, -1);
    Stack s;
    stack_init(&s, storage.data(), capacity);

    std::stack<value_type> expected;

    for (size_type i = 1; i <= capacity; ++i) {
      const value_type v = static_cast<value_type>(10 * i);

      assert(!stack_full(&s));
      stack_push(&s, v);
      expected.push(v);

      assert(stack_top(&s) == expected.top());
      assert(stack_size(&s) == expected.size());
      assert(!stack_empty(&s));
    }

    assert(stack_full(&s));
  }

  return EXIT_SUCCESS;
}
