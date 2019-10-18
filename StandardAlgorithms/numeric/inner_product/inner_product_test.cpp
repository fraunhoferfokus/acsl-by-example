
#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>
#include "inner_product.h"

int
main(int argc, char** argv)
{
  std::vector<value_type> a{1, 3, -6, 0, 4};
  std::vector<value_type> b{2, 15, 9, -3, 0};
  value_type init = 2;
  value_type result1 = inner_product(a.data(), b.data(), a.size(), init);
  value_type result2 = std::inner_product(a.begin(), a.end(), b.begin(), init);
  assert(result1 == result2);
  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

