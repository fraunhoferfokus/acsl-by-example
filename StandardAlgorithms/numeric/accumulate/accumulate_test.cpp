
#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>
#include "accumulate.h"

int main(int argc, char** argv)
{
  std::vector<value_type> a {1, 3, -6, 0, 4};
  value_type init = 2;

  value_type  result1 = accumulate(a.data(), a.size(), init);
  value_type  result2 = std::accumulate(a.begin(), a.end(), init);

  assert(result1 == result2);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

