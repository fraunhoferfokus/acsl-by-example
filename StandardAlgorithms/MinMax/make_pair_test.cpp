
#include <iostream>
#include <utility>
#include <cassert>

#include "make_pair.h"

int main(int, char** )
{
  std::pair<size_type, size_type> x(15, 4);

  size_type_pair y = make_pair(x.first, x.second);

  assert(x.first  == y.first);
  assert(x.second == y.second);

  return EXIT_SUCCESS;
}

