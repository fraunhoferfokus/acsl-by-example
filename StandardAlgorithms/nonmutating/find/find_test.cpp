
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "find.h"

int main(int argc, char** argv)
{
  std::vector<value_type> a{1, 2, 3, 3, 3, 7, 8};

  value_type value = 3;

  auto it = std::find(a.begin(), a.end(), value);
  auto pos = find(a.data(), a.size(), value);

  assert(it == a.begin() + pos);
  assert(*it == a[pos]);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

