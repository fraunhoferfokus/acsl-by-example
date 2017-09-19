
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "copy.h"

int main(int argc, char** argv)
{
  std::vector<value_type> a{1, 2, 3, 3, 3, 7, 8};

  auto a_backup = a;
  auto b = a;

  copy(a.data(), a.size(), b.data());

  assert(a == a_backup);
  assert(a == b);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

