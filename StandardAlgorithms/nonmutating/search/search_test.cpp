
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "search.h"

int
main(int argc, char** argv)
{
  std::vector<value_type> a{10, 20, 30, 40, 50, 60, 70, 80, 40, 50, 60, 70, 90};
  std::vector<value_type> b{40, 50, 60, 70};
  auto it = std::search(a.begin(), a.end(), b.begin(), b.end());
  auto pos = search(a.data(), a.size(), b.data(), b.size());
  assert(it == a.begin() + pos);
  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

