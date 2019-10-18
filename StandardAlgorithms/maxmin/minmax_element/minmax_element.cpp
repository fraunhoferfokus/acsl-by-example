
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "minmax_element.h"

int
main(int argc, char** argv)
{
  std::vector<value_type> a{1, 1, 2, 4, 5, 6, 6, 7, 8};

  for (size_t i = 0; i < a.size(); ++i) {
    auto min_it  = std::min_element(a.begin() + i, a.end());
    auto min_pos = min_element(a.data() + i, a.size() - i);
    //std::cout << min_pos << "\t" << min_it - (a.begin() + i) << std::endl;
    assert(min_pos == min_it - (a.begin() + i));
  }

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

