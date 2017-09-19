
#include <algorithm>
#include <vector>
#include <iostream>
#include <assert.h>

#include "remove.h"

int main(int argc, char** argv)
{
  std::vector<value_type> a{1, 3, 2, 8, 3, 3, 3, 7};

  auto b = a;

  const value_type value = 3;

  size_type   size_a =      remove(a.data(), a.size(), value);
  value_type* last_b = std::remove(b.data(), b.data() + a.size(), value);

  assert(size_a == last_b - b.data());
  assert(a == b);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}
