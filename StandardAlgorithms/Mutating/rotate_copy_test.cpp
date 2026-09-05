
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "rotate_copy.h"
#include "test_data.hpp"

// The destination starts out filled with a value that occurs in no test
// array, so a copy that does nothing cannot pass.
const value_type sentinel = -12345;


void test_rotate_copy(const std::vector<value_type>& a, size_type p)
{
  assert(p <= a.size());

  const std::vector<value_type> source = a;
  std::vector<value_type> b(a.size(), sentinel);
  std::vector<value_type> expected(a.size(), sentinel);

  rotate_copy(a.data(), p, a.size(), b.data());
  std::rotate_copy(a.begin(), a.begin() + p, a.end(), expected.begin());

  assert(b == expected);
  assert(a == source);
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    for (size_type p = 0; p <= a.size(); ++p) {
      test_rotate_copy(a, p);
    }
  }

  return EXIT_SUCCESS;
}
