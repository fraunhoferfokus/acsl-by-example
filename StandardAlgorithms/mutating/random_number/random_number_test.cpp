
#include "random_number.h"
#include <cassert>
#include <iostream>

int
main(int argc, char** argv)
{
  size_type n = 29;
  size_type r = random_number(n);
  assert(r < n);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

