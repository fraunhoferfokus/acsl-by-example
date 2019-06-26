
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "reverse_copy.h"

int
main(int argc, char** argv)
{
  std::vector<value_type> a{1, 3, 2, 3, 3, 8, 7};
  std::vector<value_type> a_backup(a);
  std::vector<value_type> b(a.size());
  std::vector<value_type> c(a.size());
  std::reverse_copy(a.data(), a.data() + a.size(), b.data());
  reverse_copy(b.data(), b.size(), c.data());
  assert(a == c);
  assert(a == a_backup);
  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

