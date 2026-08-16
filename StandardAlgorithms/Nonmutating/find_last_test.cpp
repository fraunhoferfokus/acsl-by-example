#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "find_last.h"

static void test_find_last(const std::vector<value_type>& a, value_type v)
{
  auto it = std::find(a.rbegin(), a.rend(), v);
  size_type expected = a.size();

  if (it != a.rend()) {
    expected = static_cast<size_type>((a.rend() - it) - 1);
  }

  assert(find_last(a.data(), a.size(), v) == expected);
}

int main(int, char**)
{
  test_find_last({}, 3);
  test_find_last({3}, 3);
  test_find_last({2}, 3);
  test_find_last({3, 3, 3}, 3);
  test_find_last({3, 2, 3}, 3);
  test_find_last({1, 2, 3}, 3);
  test_find_last({3, 2, 1}, 3);
  test_find_last({1, 2, 4}, 3);

  return EXIT_SUCCESS;
}
