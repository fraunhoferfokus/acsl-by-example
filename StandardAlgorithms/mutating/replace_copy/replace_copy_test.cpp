
#include <algorithm>
#include <vector>
#include <iostream>
#include <assert.h>

#include "replace_copy.h"

int main(int argc, char** argv)
{
  std::vector<value_type> a{1, 2, 3, 3, 3, 7, 8};
  std::vector<value_type> b(a.size());
  std::vector<value_type> c(a.size());

  const value_type old_value = 3;
  const value_type new_value = 4;

  auto last_b = std::replace_copy(&a[0], &a[0] + a.size(), &b[0], old_value, new_value);
  auto size_c =      replace_copy(&a[0], a.size(), &c[0], old_value, new_value);

  assert(size_c == last_b - &b[0]);

  assert(b == c);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

