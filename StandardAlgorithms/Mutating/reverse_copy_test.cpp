
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "reverse_copy.h"
#include "test_data.hpp"

// The destination starts out filled with a value that occurs in no test
// array, so a copy that does nothing cannot pass.
const value_type sentinel = -12345;


void test_reverse_copy(const std::vector<value_type>& a)
{
  const std::vector<value_type> source = a;
  std::vector<value_type> b(a.size(), sentinel);
  std::vector<value_type> expected(a.size(), sentinel);

  reverse_copy(a.data(), a.size(), b.data());
  std::reverse_copy(a.begin(), a.end(), expected.begin());

  assert(b == expected);
  assert(a == source);

  // Reversing the copy back yields the original.
  std::vector<value_type> c(a.size(), sentinel);
  reverse_copy(b.data(), b.size(), c.data());
  assert(c == a);
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_reverse_copy(a);

    for (size_type i = 0; i <= a.size(); ++i) {
      test_reverse_copy(std::vector<value_type>(a.begin(), a.begin() + i));
    }
  }

  return EXIT_SUCCESS;
}
