
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "rotate_copy.h"

int
main(int argc, char** argv)
{
  std::vector<value_type> a{1, 2, 3, 3, 3, 7, 8};
  std::vector<value_type> a_backup(a);
  std::vector<value_type> b(a.size());
  std::vector<value_type> c(a.size());
  size_type m = 4;
  std::rotate_copy(a.data(), a.data() + m, a.data() + a.size(), b.data());
  rotate_copy(a.data(), m, a.size(), c.data());
  assert(a == a_backup);
  assert(b == c);
  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

