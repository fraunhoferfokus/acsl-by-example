
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "adjacent_find.h"

int main(int argc, char** argv)
{
  std::vector<value_type> a{1, 2, 3, 3, 3, 7, 8};

  auto first = &a[0];
  auto last  = first + a.size();

  auto pos_std = std::adjacent_find(first, last);
  auto pos = adjacent_find(first, last - first);

  assert(pos_std  == first + pos);
  assert(*pos_std == a[pos]);
  assert(*(pos_std + 1) == a[pos + 1]);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}
