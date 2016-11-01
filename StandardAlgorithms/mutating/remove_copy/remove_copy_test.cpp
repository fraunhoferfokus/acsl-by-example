
#include <algorithm>
#include <vector>
#include <iostream>
#include <assert.h>

#include "remove_copy.h"

int main(int argc, char** argv)
{
  std::vector<value_type> a{1, 3, 2, 8, 3, 3, 7};
  std::vector<value_type> b(a.size());
  std::vector<value_type> c(a.size());

  const value_type value = 3;

  auto last_b = std::remove_copy(&a[0], &a[0] + a.size(), &b[0], value);
  auto size_c =      remove_copy(&a[0], a.size(), &c[0], value);

  assert(size_c == last_b - &b[0]);
  assert(b == c);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

