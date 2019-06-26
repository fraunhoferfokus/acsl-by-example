
#include <algorithm>
#include <vector>
#include <iostream>
#include <assert.h>

#include "remove.h"

int
main(int argc, char** argv)
{
  std::vector<value_type> a{1, 3, 2, 8, 3, 3, 7};
  std::vector<value_type> b = a;
  const value_type value = 3;
  auto last_a = std::remove(a.data(), a.data() + a.size(), value);
  auto size_b = remove(b.data(), b.size(), value);
  assert(size_b == last_a - a.data());
  assert(a == b);
  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

