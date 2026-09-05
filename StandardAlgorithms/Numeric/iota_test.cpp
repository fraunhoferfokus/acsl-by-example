
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <vector>

#include "iota.h"

// The destination starts out filled with a value iota must overwrite, so an
// implementation that writes nothing is caught.
const value_type sentinel = -12345;


void test_iota(size_type n, value_type v)
{
  std::vector<value_type> a(n, sentinel);
  std::vector<value_type> expected(n, sentinel);

  iota(a.data(), a.size(), v);
  std::iota(expected.begin(), expected.end(), v);

  assert(a == expected);

  for (size_type i = 0; i < n; ++i) {
    assert(a[i] == v + static_cast<value_type>(i));
  }
}


int main(int, char**)
{
  for (size_type n = 0; n <= 20; ++n) {
    test_iota(n, 0);
    test_iota(n, 7);
    test_iota(n, -10);
  }

  return EXIT_SUCCESS;
}
