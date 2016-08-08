
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "min_element.h"

int main(int argc, char** argv)
{

  std::vector<value_type> a{1, 2, 3, 9, 3, 7, 8};

  auto min_it  = std::min_element(a.begin(), a.end());
  auto min_pos = min_element(&a[0], a.size());

  assert(*min_it == a[min_pos]);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

