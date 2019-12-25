
#include <algorithm>
#include <random>
#include <vector>
#include <iostream>
#include <cassert>
#include <cstdlib>

#include "shuffle.h"
#include "random_number.h"

int
main(int argc, char** argv)
{
  std::vector<value_type> a{8, 2, 43, 4, 43, 6, 7};
  auto b = a;

  {
     std::vector<unsigned short> seed(3);
     random_init(seed.data());
     shuffle(a.data(), a.size(), seed.data());
  }
  {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(b.begin(), b.end(), g);
  }

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  assert(a == b);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

