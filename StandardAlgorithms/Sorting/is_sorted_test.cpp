
#include "is_sorted.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>

void test_is_sorted(std::vector<value_type> a)
{
  assert(is_sorted(a.data(), a.size()) == std::is_sorted(a.begin(), a.end()));
}


int main(int, char**)
{
  test_is_sorted(std::vector<value_type>());
  test_is_sorted(std::vector<value_type> {1});
  test_is_sorted(std::vector<value_type> {1, 5});
  test_is_sorted(std::vector<value_type> {5, 1});
  test_is_sorted(std::vector<value_type> {0, 1, 3, 5, 7, 9});
  test_is_sorted(std::vector<value_type> {9, 1, 3, 5, 7, 0});

  return EXIT_SUCCESS;
}

