
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "minmax_element.h"

int
main(int argc, char** argv)
{
  std::vector<value_type> a{2, 1, 8, 1, 5, 6, 8, 7, 7};

  auto it  = std::minmax_element(a.begin(), a.end());
  auto pos = minmax_element(a.data(), a.size());
  assert(a.begin() + pos.first  == it.first);
  assert(a.begin() + pos.second == it.second);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

