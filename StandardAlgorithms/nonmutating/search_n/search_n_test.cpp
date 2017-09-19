
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "typedefs.h"
#include "search_n.h"

void test(const std::vector<value_type>& a, size_type n, value_type v)
{
  assert(std::search_n(a.begin(), a.end(), n, v) ==
         a.begin() + search_n(a.data(), a.size(), n, v));
}

int main(int argc, char** argv)
{
  std::vector<value_type> a{0, 4, 4, 4, 5, 4, 4, 4, 4};

  // successful nontrivial search
  test(a, 3, 7);

  // failing nontrivial search
  test(a, 6, 4);

  // search for empty range
  test(a, 0, 4);

  // search in empty range
  test(a, 1, 4);

  // search for too large range
  test(a, 20, 4);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

