
#include "is_sorted_until.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cassert>

void test_is_sorted_until(std::vector<value_type> a)
{
  const auto expected =
    std::distance(a.begin(), std::is_sorted_until(a.begin(), a.end()));

  assert(is_sorted_until(a.data(), a.size()) == expected);
}


int main(int, char**)
{
  test_is_sorted_until(std::vector<value_type>());
  test_is_sorted_until(std::vector<value_type> {1});
  test_is_sorted_until(std::vector<value_type> {1, 5});
  test_is_sorted_until(std::vector<value_type> {5, 1});
  test_is_sorted_until(std::vector<value_type> {0, 1, 3, 5, 7, 9});
  test_is_sorted_until(std::vector<value_type> {9, 1, 3, 5, 7, 0});

  return EXIT_SUCCESS;
}

