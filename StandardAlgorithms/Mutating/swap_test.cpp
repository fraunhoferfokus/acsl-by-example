
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "swap.h"
#include "test_data.hpp"

void test_swap(std::vector<value_type> a, size_type i, size_type j)
{
  const std::vector<value_type> original = a;
  std::vector<value_type> expected = a;

  swap(a.data() + i, a.data() + j);
  std::iter_swap(expected.begin() + i, expected.begin() + j);

  assert(a == expected);

  // A swap is its own inverse.
  swap(a.data() + i, a.data() + j);
  assert(a == original);
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    for (size_type i = 0; i < a.size(); ++i) {
      for (size_type j = i; j < a.size(); ++j) {
        test_swap(a, i, j);      // j == i covers swapping an element with itself
      }
    }
  }

  return EXIT_SUCCESS;
}
