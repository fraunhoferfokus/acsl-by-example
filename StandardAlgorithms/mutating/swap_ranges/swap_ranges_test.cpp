
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "swap_ranges.h"

int
main(int argc, char** argv)
{
  std::vector<value_type> a{1, 4, 2, 3};
  auto a_backup = a;
  std::vector<value_type> b{11, 17, 15, 18};
  auto b_backup = b;
  std::swap_ranges(a.begin(), a.end(), b.begin());
  assert(b == a_backup);
  assert(a == b_backup);
  swap_ranges(b.data(), b.size(), a.data());
  assert(a == a_backup);
  assert(b == b_backup);
  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

