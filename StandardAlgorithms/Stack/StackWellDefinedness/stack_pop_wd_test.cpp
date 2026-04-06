
#include <cassert>
#include <cstdlib>
#include <vector>

#include "stack_functions.h"
#include "stack_pop.h"
#include "stack_top.h"
#include "stack_empty.h"

// This test targets the contract of stack_pop_wd:
//
// If s and t are observationally equal and separated,
// then popping both preserves observational equality
// and decreases size consistently.

int main(int, char**)
{
  std::vector<value_type> storage1(10);
  std::vector<value_type> storage2(6);

  Stack s1, s2;
  stack_init(&s1, storage1.data(), storage1.size());
  stack_init(&s2, storage2.data(), storage2.size());

  // Separation in practice (distinct backing stores).
  assert(s1.data != s2.data);

  // Establish observational equality with a common sequence.
  stack_push(&s1, 10);
  stack_push(&s2, 10);
  stack_push(&s1, 20);
  stack_push(&s2, 20);
  stack_push(&s1, 30);
  stack_push(&s2, 30);

  assert(stack_equal(&s1, &s2));
  assert(!stack_empty(&s1));
  assert(!stack_empty(&s2));

  // Remember sizes and (optionally) the current top.
  const size_type sz1_pre = s1.sz;
  const size_type sz2_pre = s2.sz;
  assert(sz1_pre == sz2_pre);

  const value_type top_pre_1 = stack_top(&s1);
  const value_type top_pre_2 = stack_top(&s2);
  assert(top_pre_1 == top_pre_2);

  // Pop both.
  stack_pop(&s1);
  stack_pop(&s2);

  // Postconditions: still equal.
  assert(stack_equal(&s1, &s2));

  // Size decreased by one on both (this is the main observable effect).
  assert(s1.sz == sz1_pre - 1);
  assert(s2.sz == sz2_pre - 1);

  // New tops match as well (if not empty now).
  if (!stack_empty(&s1)) {
    assert(!stack_empty(&s2));
    assert(stack_top(&s1) == stack_top(&s2));
  }
  else {
    assert(stack_empty(&s2));
  }

  // Pop down to empty, checking equality at each step.
  while (!stack_empty(&s1)) {
    assert(stack_equal(&s1, &s2));
    stack_pop(&s1);
    stack_pop(&s2);
    assert(stack_equal(&s1, &s2));
  }

  assert(stack_empty(&s2));

  return EXIT_SUCCESS;
}

