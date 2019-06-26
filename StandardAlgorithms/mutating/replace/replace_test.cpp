
#include <algorithm>
#include <vector>
#include <iostream>
#include <assert.h>

#include "replace.h"

int
main(int argc, char** argv)
{
  std::vector<value_type> a{1, 2, 3, 3, 3, 7, 8};
  auto b = a;
  assert(a == b);
  const value_type old_value = 3;
  const value_type new_value = 4;
  replace(a.data(), a.size(), old_value, new_value);
  std::replace(b.begin(), b.end(), old_value, new_value);
  assert(a == b);
  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

