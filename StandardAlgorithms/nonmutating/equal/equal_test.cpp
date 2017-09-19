
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "equal.h"

int main(int argc, char** argv)
{
  std::vector<value_type> a{1, 2, 3, 3, 3, 7, 8};

  auto b = a;

  assert(std::equal(a.begin(), a.end(), b.begin()));
  assert(equal(a.data(), a.size(), b.data()));

  auto c = a;
  c.front() += 1;

  assert(!std::equal(a.begin(), a.end(), c.begin()));
  assert(!equal(a.data(), a.size(), c.data()));

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}
