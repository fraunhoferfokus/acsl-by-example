
#include <cassert>
#include <cstdlib>
#include <vector>

#include "stack_init.h"
#include "stack_capacity.h"
#include "stack_test.hpp"

// An initialised stack is empty and holds the capacity it was given,
// whatever the storage contained before.
int main(int, char**)
{
  for (const size_type capacity : test_capacities()) {
    std::vector<value_type> storage(capacity, 42);
    Stack s;

    stack_init(&s, storage.data(), capacity);

    assert(stack_size(&s) == 0);
    assert(stack_capacity(&s) == capacity);
    assert(stack_empty(&s));
    assert(!stack_full(&s));

    // Initialising a used stack again empties it.
    stack_push(&s, 1);
    assert(!stack_empty(&s));
    stack_init(&s, storage.data(), capacity);
    assert(stack_empty(&s));
    assert(stack_size(&s) == 0);
  }

  return EXIT_SUCCESS;
}
