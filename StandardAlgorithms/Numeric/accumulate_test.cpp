
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <vector>

#include "accumulate.h"
#include "test_data.hpp"

// The contract requires AccumulateBounds, so the values stay small enough
// that no partial sum overflows.
void test_accumulate(const std::vector<value_type>& a, value_type init)
{
  const std::vector<value_type> source = a;

  assert(accumulate(a.data(), a.size(), init) ==
         std::accumulate(a.begin(), a.end(), init));
  assert(a == source);
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_accumulate(a, 0);
    test_accumulate(a, 2);
    test_accumulate(a, -2);
  }

  // The empty array returns the initial value unchanged.
  assert(accumulate(std::vector<value_type>().data(), 0, 42) == 42);

  test_accumulate({1, 3, -6, 0, 4}, 2);      // the array this test used to run
  test_accumulate({-1, -2, -3}, 0);          // negative values

  return EXIT_SUCCESS;
}
