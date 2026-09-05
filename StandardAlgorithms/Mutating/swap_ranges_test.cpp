
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "swap_ranges.h"
#include "test_data.hpp"

void test_swap_ranges(std::vector<value_type> a, std::vector<value_type> b)
{
  assert(a.size() == b.size());

  const std::vector<value_type> a_before = a;
  const std::vector<value_type> b_before = b;

  swap_ranges(a.data(), a.size(), b.data());

  assert(a == b_before);
  assert(b == a_before);

  // Swapping back restores both arrays.
  swap_ranges(a.data(), a.size(), b.data());
  assert(a == a_before);
  assert(b == b_before);
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    std::vector<value_type> b(a.size());

    for (size_type i = 0; i < a.size(); ++i) {
      b[i] = static_cast<value_type>(100 + i);
    }

    test_swap_ranges(a, b);
    test_swap_ranges(a, a);      // equal contents
  }

  return EXIT_SUCCESS;
}
