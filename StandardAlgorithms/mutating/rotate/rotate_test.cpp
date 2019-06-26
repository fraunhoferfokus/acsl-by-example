
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "rotate.h"

int
main(int argc, char** argv)
{
  std::vector<value_type> a{1, 2, 3, 4, 5, 6, 7, 8};
  auto b = a;
  size_type m = 5;
  std::rotate(a.data(), a.data() + m, a.data() + a.size());
  rotate(b.data(), m, b.size());
  assert(a == b);
  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

