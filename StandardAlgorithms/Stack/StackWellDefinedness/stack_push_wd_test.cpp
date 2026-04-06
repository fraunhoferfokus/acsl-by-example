
#include <cassert>
#include <cstdlib>
#include <vector>

#include "stack_functions.h"
#include "stack_push.h"
#include "stack_top.h"
#include "stack_empty.h"

// This test targets the contract of stack_push_wd:
//
// If s and t are observationally equal, not full, and separated,
// then pushing the same value v onto both preserves observational
// equality, and the new top is v for both.

int main(int, char**)
{
  std::vector<value_type> storage1(10);
  std::vector<value_type> storage2(6);

  Stack s1, s2;
  stack_init(&s1, storage1.data(), storage1.size());
  stack_init(&s2, storage2.data(), storage2.size());

  // Different capacities, but distinct storage: separation in practice.
  assert(s1.cap != s2.cap);
  assert(s1.data != s2.data);

  // Establish observational equality with a shared prefix sequence.
  stack_push(&s1, 1);
  stack_push(&s2, 1);
  stack_push(&s1, 2);
  stack_push(&s2, 2);

  assert(stack_equal(&s1, &s2));

  // Not full precondition (both must have room).
  assert(!stack_full(&s1));
  assert(!stack_full(&s2));

  // Keep the old size for a post-check (mirrors StackSize{Pre}(s)).
  const size_type sz1_pre = s1.sz;
  const size_type sz2_pre = s2.sz;
  assert(sz1_pre == sz2_pre);

  // Push the same value onto both stacks.
  const value_type v = 42;
  stack_push(&s1, v);
  stack_push(&s2, v);

  // Postconditions / well-definedness effects:

  // (1) Both stacks remain observationally equal.
  assert(stack_equal(&s1, &s2));

  // (2) Size increased by one on both.
  assert(s1.sz == sz1_pre + 1);
  assert(s2.sz == sz2_pre + 1);

  // (3) New top is v on both (matches the ACSL asserts).
  assert(!stack_empty(&s1));
  assert(!stack_empty(&s2));
  assert(stack_top(&s1) == v);
  assert(stack_top(&s2) == v);

  // (4) The element just written is indeed v (stronger, low-level check).
  assert(s1.data[sz1_pre] == v);
  assert(s2.data[sz2_pre] == v);

  // Repeat with another value to catch state-dependent bugs.
  const value_type w = -7;
  assert(!stack_full(&s1));
  assert(!stack_full(&s2));

  const size_type sz1_pre2 = s1.sz;
  const size_type sz2_pre2 = s2.sz;

  stack_push(&s1, w);
  stack_push(&s2, w);

  assert(stack_equal(&s1, &s2));
  assert(s1.sz == sz1_pre2 + 1);
  assert(s2.sz == sz2_pre2 + 1);
  assert(stack_top(&s1) == w);
  assert(stack_top(&s2) == w);

  return EXIT_SUCCESS;
}

