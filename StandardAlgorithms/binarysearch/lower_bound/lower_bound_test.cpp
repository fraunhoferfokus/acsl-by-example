
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <functional>

#include "lower_bound.h"
#include "../partitioned_test.h"

void lower_bound_test(const std::vector<value_type>& a, value_type value, size_type pos)
{
  auto pred = [value](value_type x) {
    return x < value;
  };

  {
    assert(pos == lower_bound(a.data(), a.size(), value));
    auto ptr = a.data();
    assert(ptr + pos == std::partition_point(ptr, ptr + a.size(), pred));
  }
  {
    auto it = std::lower_bound(a.begin(), a.end(), value);
    assert(it == a.begin() + pos);
    assert(it == std::partition_point(a.begin(), a.end(), pred));
  }
}

int main(int argc, char** argv)
{
  auto a = binary_search_data();

  lower_bound_test(a, 1, 0);
  lower_bound_test(a, 2, 0);
  lower_bound_test(a, 3, 1);
  lower_bound_test(a, 5, 4);
  lower_bound_test(a, 11, 6);
  lower_bound_test(a, 14, 7);
  lower_bound_test(a, 17, 9);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}
