
#include <cassert>
#include <cstdlib>
#include <stack>
#include <vector>

#include "stack_pop.h"
#include "stack_test.hpp"

// Every pop must remove the top and uncover the one below it, all the way
// down to the empty stack.
int main(int, char**)
{
  for (const size_type capacity : test_capacities()) {
    std::vector<value_type> storage(capacity, -1);
    Stack s;
    stack_init(&s, storage.data(), capacity);

    std::stack<value_type> expected;

    for (size_type i = 1; i <= capacity; ++i) {
      const value_type v = static_cast<value_type>(10 * i);
      stack_push(&s, v);
      expected.push(v);
    }

    while (!expected.empty()) {
      assert(stack_top(&s) == expected.top());
      stack_pop(&s);
      expected.pop();

      assert(stack_size(&s) == expected.size());
      assert(stack_empty(&s) == expected.empty());
      assert(!stack_full(&s) || capacity == 0);
    }

    assert(stack_empty(&s));
  }

  return EXIT_SUCCESS;
}
