#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "equal_range2.h"
#include "../partitioned_test.h"

void
equal_range2_test(const std::vector<value_type>& a, value_type value,
                  size_type lower, size_type upper)
{
  auto less = [value](value_type x) {
    return x < value;
  };
  auto less_equal = [value](value_type x) {
    return x <= value;
  };
  {
    auto pair = equal_range2(a.data(), a.size(), value);
    assert(lower == pair.first);
    assert(upper == pair.second);
    auto ptr = a.data();
    assert(ptr + lower == std::partition_point(ptr, ptr + a.size(), less));
    assert(ptr + upper == std::partition_point(ptr, ptr + a.size(), less_equal));
  }
  {
    auto pair = std::equal_range(a.begin(), a.end(), value);
    assert(pair.first  == a.begin() + lower);
    assert(pair.second == a.begin() + upper);
    assert(pair.first  == std::partition_point(a.begin(), a.end(), less));
    assert(pair.second == std::partition_point(a.begin(), a.end(), less_equal));
  }
}

int
main(int argc, char** argv)
{
  auto a = binary_search_data();
  equal_range2_test(a, 1, 0,  0);
  equal_range2_test(a, 2, 0,  1);
  equal_range2_test(a, 3, 1,  4);
  equal_range2_test(a, 5, 4,  4);
  equal_range2_test(a, 11, 6, 7);
  equal_range2_test(a, 14, 7, 9);
  equal_range2_test(a, 17, 9, 9);
  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}
