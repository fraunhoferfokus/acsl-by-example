
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "count.h"
#include "test_data.hpp"

void test_count(const std::vector<value_type>& a, value_type v)
{
  const auto expected = std::count(a.begin(), a.end(), v);

  assert(count(a.data(), a.size(), v) == static_cast<size_type>(expected));
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    std::vector<value_type> values = a;
    values.push_back(present_value());
    values.push_back(absent_value());

    for (const value_type v : values) {
      test_count(a, v);
    }
  }

  return EXIT_SUCCESS;
}
