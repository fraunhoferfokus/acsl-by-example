#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

#include "upper_bound.h"
#include "../partitioned_test.h"

void
upper_bound_test(const std::vector<value_type>& a, value_type value, size_type pos)
{
  auto pred = [value](value_type x) {
    return x <= value; // or: !(value < x)
  };
  {
    assert(pos == upper_bound(a.data(), a.size(), value));
    auto ptr = a.data();
    assert(ptr + pos == std::partition_point(ptr, ptr + a.size(), pred));
  }
  {
    auto it = std::upper_bound(a.begin(), a.end(), value);
    assert(it == a.begin() + pos);
    assert(it == std::partition_point(a.begin(), a.end(), pred));
  }
}


int
main(int argc, char** argv)
{
  std::vector<value_type> a = binary_search_data();
  upper_bound_test(a, 1, 0);
  upper_bound_test(a, 2, 1);
  upper_bound_test(a, 3, 4);
  upper_bound_test(a, 5, 4);
  upper_bound_test(a, 8, 6);
  upper_bound_test(a, 11, 7);
  upper_bound_test(a, 14, 9);
  upper_bound_test(a, 17, 9);
  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}
