
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "copy_backward.h"
#include "test_data.hpp"

// The destination starts out filled with a value that occurs in no test
// array, so a copy that does nothing cannot pass.
const value_type sentinel = -12345;


void test_copy_backward(const std::vector<value_type>& a)
{
  const std::vector<value_type> source = a;
  std::vector<value_type> b(a.size(), sentinel);
  std::vector<value_type> expected(a.size(), sentinel);

  copy_backward(a.data(), a.size(), b.data());
  std::copy_backward(a.begin(), a.end(), expected.end());

  assert(b == expected);
  assert(a == source);
}


// The precondition separates the source from the position one past the
// destination only. Copying towards the end of one array is therefore
// allowed, and it is what copy_backward exists for: reading from the end
// keeps an element from being overwritten before it has been read.
void test_copy_to_the_right(size_type n, size_type shift)
{
  std::vector<value_type> a(n + shift);

  for (size_type i = 0; i < a.size(); ++i) {
    a[i] = static_cast<value_type>(i);
  }

  std::vector<value_type> expected = a;

  copy_backward(a.data(), n, a.data() + shift);
  std::copy_backward(expected.begin(), expected.begin() + n,
                     expected.begin() + shift + n);

  assert(a == expected);
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_copy_backward(a);
  }

  for (size_type n = 0; n <= 8; ++n) {
    for (size_type shift = 1; shift <= 4; ++shift) {
      test_copy_to_the_right(n, shift);
    }
  }

  return EXIT_SUCCESS;
}
