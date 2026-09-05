
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "reverse.h"
#include "test_data.hpp"

void test_reverse(std::vector<value_type> a)
{
  const std::vector<value_type> original = a;
  std::vector<value_type> expected = a;

  reverse(a.data(), a.size());
  std::reverse(expected.begin(), expected.end());

  assert(a == expected);

  // Reversing twice restores the array, whatever its length's parity.
  reverse(a.data(), a.size());
  assert(a == original);
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_reverse(a);

    // Both parities of the length.
    for (size_type i = 0; i <= a.size(); ++i) {
      test_reverse(std::vector<value_type>(a.begin(), a.begin() + i));
    }
  }

  return EXIT_SUCCESS;
}
