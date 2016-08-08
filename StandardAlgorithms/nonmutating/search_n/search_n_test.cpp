
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "typedefs.h"
#include "search_n.h"

int main(int argc, char** argv)
{
  std::vector<value_type> a{00, 42, 42, 42, 40, 42, 42, 42, 42};
  //std::vector<value_type> a{00, 42, 42, 30, 40, 42, 42, 42, 42};
  //std::vector<value_type> a{00, 10, 20, 30, 40, 42, 42, 42, 42};
  //std::vector<value_type> a{00, 10, 20, 30, 40, 50, 42, 42, 42};
  //std::vector<value_type> a{00, 10, 20, 30, 40, 50, 60, 42, 42};
  //std::vector<value_type> a{00, 10, 20, 30, 40, 50, 60, 70, 80};
  //std::vector<value_type> a{00, 10, 20, 42, 42, 42, 60, 70, 80};

  auto it = std::search_n(a.begin(), a.end(), 3, 42);

  auto pos = search_n(&a[0], 9, 3, 42);
  assert(it == a.begin() + pos);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

