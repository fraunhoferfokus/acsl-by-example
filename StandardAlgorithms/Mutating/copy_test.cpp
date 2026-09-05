
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "copy.h"
#include "test_data.hpp"

// The destination starts out filled with a value that occurs in no test
// array, so a copy that does nothing cannot pass.
const value_type sentinel = -12345;


void test_copy(const std::vector<value_type>& a)
{
  const std::vector<value_type> source = a;
  std::vector<value_type> b(a.size(), sentinel);
  std::vector<value_type> expected(a.size(), sentinel);

  copy(a.data(), a.size(), b.data());
  std::copy(a.begin(), a.end(), expected.begin());

  assert(b == expected);
  assert(a == source);
}


// The precondition separates the source from the *first* element of the
// destination only, so copying towards the beginning of one array is
// allowed: no element is overwritten before it has been read.
void test_copy_to_the_left(size_type n, size_type shift)
{
  std::vector<value_type> a(n + shift);

  for (size_type i = 0; i < a.size(); ++i) {
    a[i] = static_cast<value_type>(i);
  }

  std::vector<value_type> expected = a;

  copy(a.data() + shift, n, a.data());
  std::copy(expected.begin() + shift, expected.begin() + shift + n,
            expected.begin());

  assert(a == expected);
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_copy(a);
  }

  for (size_type n = 0; n <= 8; ++n) {
    for (size_type shift = 1; shift <= 4; ++shift) {
      test_copy_to_the_left(n, shift);
    }
  }

  return EXIT_SUCCESS;
}
