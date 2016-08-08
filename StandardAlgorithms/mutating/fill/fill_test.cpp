
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "fill.h"

int main(int argc, char** argv)
{
  std::vector<value_type> a{1, 2, 3, 3, 3, 7, 8};

  auto b = a;

  value_type value = 9;

  std::fill(&a[0], &a[0] + a.size(), value);
  fill(&b[0], b.size(), value);

  assert(a == b);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

