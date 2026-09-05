
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "rotate.h"
#include "test_data.hpp"

// rotate moves the prefix of length p behind the rest and returns n-p, the
// position the first element ends up at. The contract admits p == 0 and
// p == n, where the array must stay as it is.
void test_rotate(std::vector<value_type> a, size_type p)
{
  assert(p <= a.size());

  std::vector<value_type> expected = a;

  const size_type result = rotate(a.data(), p, a.size());
  std::rotate(expected.begin(), expected.begin() + p, expected.end());

  assert(result == a.size() - p);
  assert(a == expected);
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    // Every admissible rotation, the two degenerate ones included.
    for (size_type p = 0; p <= a.size(); ++p) {
      test_rotate(a, p);
    }
  }

  return EXIT_SUCCESS;
}
