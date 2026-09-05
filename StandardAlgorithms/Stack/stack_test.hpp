
#ifndef STACK_TEST_HPP_INCLUDED
#define STACK_TEST_HPP_INCLUDED

#include <cassert>
#include <vector>

#include "stack_functions.h"

// The stack tests used to look at a freshly initialised stack only, so
// stack_empty was never seen returning false and stack_full never returning
// true. This walks a stack from empty to full and back, calling the given
// check after every operation with the number of elements the stack then
// holds. The value pushed at step i is i, so the top is always the size.
template<class Check>
void walk_stack(size_type capacity, Check check)
{
  assert(0 < capacity);

  std::vector<value_type> storage(capacity, -1);
  Stack s;

  stack_init(&s, storage.data(), capacity);
  check(s, static_cast<size_type>(0), capacity);

  for (size_type i = 1; i <= capacity; ++i) {
    stack_push(&s, static_cast<value_type>(i));
    check(s, i, capacity);
  }

  for (size_type i = capacity; 0 < i; --i) {
    stack_pop(&s);
    check(s, i - 1, capacity);
  }
}


// The capacities every stack test is run with: the smallest admissible one
// first.
inline std::vector<size_type> test_capacities()
{
  return std::vector<size_type> {1, 2, 3, 8, 17};
}

#endif /* STACK_TEST_HPP_INCLUDED */
