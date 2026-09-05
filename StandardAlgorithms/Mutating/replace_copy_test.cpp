
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "replace_copy.h"
#include "test_data.hpp"

// The destination starts out filled with a value that occurs in no test
// array, so a copy that does nothing cannot pass.
const value_type sentinel = -12345;


void test_replace_copy(const std::vector<value_type>& a, value_type v, value_type w)
{
  const std::vector<value_type> source = a;
  std::vector<value_type> b(a.size(), sentinel);
  std::vector<value_type> expected(a.size(), sentinel);

  const size_type written = replace_copy(a.data(), a.size(), b.data(), v, w);
  std::replace_copy(a.begin(), a.end(), expected.begin(), v, w);

  assert(written == a.size());
  assert(b == expected);
  assert(a == source);
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_replace_copy(a, present_value(), 4);
    test_replace_copy(a, absent_value(), 4);        // nothing is replaced
    test_replace_copy(a, present_value(), present_value());

    for (size_type i = 0; i < a.size(); ++i) {
      test_replace_copy(a, a[i], absent_value());
    }
  }

  return EXIT_SUCCESS;
}
