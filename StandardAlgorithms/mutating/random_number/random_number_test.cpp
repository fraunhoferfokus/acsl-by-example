
#include "random_number.h"
#include <cassert>
#include <iostream>

int
main(int argc, char** argv)
{
  size_type n = 29;
  unsigned short rand[3];
  random_init(rand);

  size_type r = random_number(rand, n);
  assert(r < n);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

