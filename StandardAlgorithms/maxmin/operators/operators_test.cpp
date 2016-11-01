
#include <functional>
#include <iostream>
#include <cassert>

#include "typedefs.h"

int main(int argc, char** argv)
{
  value_type a = 0;
  value_type b = 1;

  assert(a < b);
  assert(std::less<value_type>()(a, b));

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

