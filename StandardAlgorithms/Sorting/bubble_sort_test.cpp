
#include "bubble_sort.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <random>


int main(int, char**)
{
  std::vector<value_type> a{1, 1, 2, 4, 5, 6, 6, 7, 8};
  assert(std::is_sorted(a.begin(), a.end()));
  auto save = a;
  {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(a.begin(), a.end(), g);
  }

  bubble_sort(a.data(), a.size());
  assert(a == save);

  return EXIT_SUCCESS;
}

