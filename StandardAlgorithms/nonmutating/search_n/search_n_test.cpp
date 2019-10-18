
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "typedefs.h"
#include "search_n.h"

void
test(const std::vector<value_type>& a, value_type v, size_type n)
{
  assert(std::search_n(a.begin(), a.end(), n, v) ==
         a.begin() + search_n(a.data(), a.size(), v, n));
}

int
main(int argc, char** argv)
{
  std::vector<value_type> a{0, 4, 4, 4, 5, 4, 4, 4, 4};

  // successful nontrivial search
  test(a, 7, 3);
  // failing nontrivial search
  test(a, 4, 6);
  // search for empty range
  test(a, 4, 0);
  // search in empty range
  test(a, 4, 1);
  // search for too large range
  test(a, 4, 20);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

