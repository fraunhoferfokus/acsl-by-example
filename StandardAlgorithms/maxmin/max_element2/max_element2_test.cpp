
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "max_element2.h"

int main(int argc, char** argv)
{

  std::vector<value_type> a{1, 2, 3, 9, 3, 7, 8};

  auto max_it  = std::max_element(a.begin(), a.end());
  auto max_pos = max_element(a.data(), a.size());

  assert(*max_it == a[max_pos]);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

