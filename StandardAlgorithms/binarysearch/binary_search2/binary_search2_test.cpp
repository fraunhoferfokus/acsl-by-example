
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "binary_search2.h"

int main(int argc, char** argv)
{
  std::vector<value_type> a{1, 2, 3, 3, 3, 7, 8};

  value_type value = 3;

  bool result1 = std::binary_search(a.begin(), a.end(), value);
  assert(result1);

  bool result2 = binary_search(&a[0], a.size(), value);
  assert(result1 == result2);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}


