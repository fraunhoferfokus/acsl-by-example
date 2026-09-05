
#include <algorithm>
#include <cassert>
#include <cstdlib>

#include "clamp.h"

// The contract has three disjoint behaviours -- below the range, inside it,
// above it -- and the earlier test only exercised the middle one.
void test_clamp(value_type v, value_type lower, value_type upper)
{
  assert(lower < upper);

  const value_type result = clamp(v, lower, upper);

  assert(result == std::clamp(v, lower, upper));
  assert(lower <= result && result <= upper);

  if (v < lower) {
    assert(result == lower);
  }
  else if (v <= upper) {
    assert(result == v);
  }
  else {
    assert(result == upper);
  }
}


int main(int, char**)
{
  const value_type lower = 10;
  const value_type upper = 100;

  test_clamp(-5,     lower, upper);   // far below
  test_clamp(9,      lower, upper);   // just below
  test_clamp(lower,  lower, upper);   // at the lower bound
  test_clamp(20,     lower, upper);   // inside
  test_clamp(upper,  lower, upper);   // at the upper bound
  test_clamp(101,    lower, upper);   // just above
  test_clamp(1000,   lower, upper);   // far above

  // The narrowest admissible range: lower < upper.
  test_clamp(-1, 0, 1);
  test_clamp(0,  0, 1);
  test_clamp(1,  0, 1);
  test_clamp(2,  0, 1);

  return EXIT_SUCCESS;
}
