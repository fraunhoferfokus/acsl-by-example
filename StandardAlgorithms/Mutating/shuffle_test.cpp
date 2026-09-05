
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "shuffle.h"
#include "random_number.h"
#include "test_data.hpp"

// The contract promises a reordering and nothing more, so the multiset of
// values is what a test may check. random_init installs a fixed seed, so the
// result is the same on every run.
void test_shuffle(std::vector<value_type> a)
{
  std::vector<value_type> expected = a;

  std::vector<unsigned short> seed(3);
  random_init(seed.data());
  shuffle(a.data(), a.size(), seed.data());

  std::sort(a.begin(), a.end());
  std::sort(expected.begin(), expected.end());
  assert(a == expected);
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_shuffle(a);
  }

  // A long array of distinct values: a shuffle that did nothing would
  // preserve the multiset too, so check that this one moves something.
  {
    std::vector<value_type> a(20);

    for (size_type i = 0; i < a.size(); ++i) {
      a[i] = static_cast<value_type>(i);
    }

    const std::vector<value_type> original = a;

    std::vector<unsigned short> seed(3);
    random_init(seed.data());
    shuffle(a.data(), a.size(), seed.data());

    assert(a != original);

    std::vector<value_type> sorted = a;
    std::sort(sorted.begin(), sorted.end());
    assert(sorted == original);
  }

  return EXIT_SUCCESS;
}
