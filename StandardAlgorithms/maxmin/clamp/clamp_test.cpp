
#include <iostream>
#include <cassert>
#include <algorithm>
#include "clamp.h"

int
main(int argc, char** argv)
{

  auto result1 = clamp(20, 10, 100);
  auto result2 = std::clamp(20, 10, 100);
  assert(result1 == result2);
  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

