#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "all_of.h"

static void test_all_of(const std::vector<value_type>& a, value_type v)
{
  auto pred = [v](value_type x) {
    return x == v;
  };
  assert(all_of(a.data(), a.size(), v) == std::all_of(a.begin(), a.end(), pred));
}

int main(int, char**)
{
  test_all_of({}, 3);
  test_all_of({3}, 3);
  test_all_of({2}, 3);
  test_all_of({3, 3, 3}, 3);
  test_all_of({3, 2, 3}, 3);
  test_all_of({1, 2, 3}, 3);

  return EXIT_SUCCESS;
}
