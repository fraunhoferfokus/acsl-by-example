
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "max_seq.h"

int main(int argc, char** argv)
{
  std::vector<value_type> a{1, 2, 3, 9, 3, 7, 8};

  assert(not a.empty());

  auto max_it  = std::max_element(a.begin(), a.end());
  auto max = max_seq(&a[0], a.size());

  assert(*max_it == max);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

