
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "copy_backward.h"

int main(int argc, char** argv)
{
  std::vector<value_type> a{1, 2, 3, 3, 3, 7, 8};

  auto a_backup = a;
  auto b = a;

  copy_backward(&a[0], a.size(), &b[0]);

  assert(a == a_backup);
  assert(a == b);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

