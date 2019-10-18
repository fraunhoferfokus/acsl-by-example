
#include <iostream>
#include <utility>
#include "make_pair.h"

int
main(int argc, char** argv)
{
  std::pair<size_type, size_type> x(15, 4);

  size_type_pair y = make_pair(x.first, x.second);

  assert(x.first  == y.first);
  assert(x.second == y.second);

  std::cout << "\tsuccessful execution of " << argv[0] << std::endl;
  return EXIT_SUCCESS;
}

