
#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>
#include "numeric.h"
#include "adjacent_difference.h"

int main(int argc, char** argv)
{
  std::vector<value_type> a{1, 5, -2, 4, 0};
  std::vector<value_type> result1(a.size());
  std::vector<value_type> result2(a.size());

  adjacent_difference(a.data(), a.size(), result1.data());
  std::adjacent_difference(a.begin(), a.end(), result2.begin());

  assert(result1 == result2);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

