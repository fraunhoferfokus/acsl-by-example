#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "none_of.h"

static void test_none_of(const std::vector<value_type>& a, value_type v)
{
  auto pred = [v](value_type x) {
    return x == v;
  };
  assert(none_of(a.data(), a.size(), v) == std::none_of(a.begin(), a.end(), pred));
}

int main(int, char**)
{
  test_none_of({}, 3);
  test_none_of({3}, 3);
  test_none_of({2}, 3);
  test_none_of({3, 3, 3}, 3);
  test_none_of({3, 2, 3}, 3);
  test_none_of({1, 2, 3}, 3);

  return EXIT_SUCCESS;
}
