
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "count2.h"

int
main(int argc, char** argv)
{
  std::vector<value_type> a{1, 2, 3, 3, 3, 7, 8};
  value_type count_value = 3;
  auto c1 = std::count(a.begin(), a.end(), count_value);
  auto c2 = count2(a.data(), a.size(), count_value);
  assert(c1 = c2);
  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}
