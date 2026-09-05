
#ifndef SORT_TEST_HPP_INCLUDED
#define SORT_TEST_HPP_INCLUDED

#include "typedefs.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <random>


// Sort a copy of a with the given sort function and compare with std::sort.
template<class Sort>
void check_cases(Sort sort, std::vector<value_type> a)
{
  auto expected = a;
  std::sort(expected.begin(), expected.end());
  sort(a.data(), a.size());
  assert(a == expected);
}


// The hand-picked cases, the empty array first, followed by one shuffled
// array: sorting it must restore the original order, which checks the
// ordering and the permutation property at once. Returns an exit status,
// reporting the seed so that a failing shuffle can be reproduced.
template<class Sort>
int check_sort(const char* name, Sort sort)
{
  check_cases(sort, std::vector<value_type>());
  check_cases(sort, std::vector<value_type> {1});
  check_cases(sort, std::vector<value_type> {1, 5});
  check_cases(sort, std::vector<value_type> {5, 1});
  check_cases(sort, std::vector<value_type> {0, 1, 3, 5, 7, 9});
  check_cases(sort, std::vector<value_type> {9, 1, 3, 5, 7, 0});
  check_cases(sort, std::vector<value_type> {1, 1, 2, 4, 5, 6, 6, 7, 8});

  std::vector<value_type> a{1, 1, 2, 4, 5, 6, 6, 7, 8};
  assert(std::is_sorted(a.begin(), a.end()));
  const auto save = a;
  std::random_device rd;
  const auto seed = rd();
  std::mt19937 g(seed);
  std::shuffle(a.begin(), a.end(), g);

  sort(a.data(), a.size());

  if (a != save) {
    std::cerr << name << " failed for shuffle seed " << seed << '\n';
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

#endif /* SORT_TEST_HPP_INCLUDED */
