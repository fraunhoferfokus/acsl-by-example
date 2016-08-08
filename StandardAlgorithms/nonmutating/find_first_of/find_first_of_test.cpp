
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "find_first_of.h"

int main(int argc, char** argv)
{
  std::vector<value_type> a{1, 2, 3, 3, 3, 7, 8};

  std::vector<value_type> b{0, 3, 9};

  auto it = std::find_first_of(&a[0], &a[0] + a.size(), &b[0], &b[0] + b.size());

  auto pos = find_first_of(&a[0], a.size(), &b[0], b.size());

  assert(it == &a[0] + pos);
  assert(*it == a[pos]);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

