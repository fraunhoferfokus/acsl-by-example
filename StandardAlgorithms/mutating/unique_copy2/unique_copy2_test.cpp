
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <vector>

#include "unique_copy2.h"

int main(int argc, char** argv)
{
  std::vector<value_type> a{1, 2, 2, 8, 3, 3, 7};
  std::vector<value_type> b(a.size());
  std::vector<value_type> c(a.size());

  auto last_b = std::unique_copy(a.data(), a.data() + a.size(), b.data());
  auto size_c =      unique_copy(a.data(), a.size(), c.data());

  assert(size_c == last_b  - b.data());
  assert(b == c);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

