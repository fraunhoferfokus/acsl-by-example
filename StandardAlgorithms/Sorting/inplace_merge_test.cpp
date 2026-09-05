
#include "inplace_merge.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <functional>
#include <random>


// Both halves must be increasing, as required by the contract of inplace_merge.
void test_inplace_merge(std::vector<value_type> a, size_type m)
{
  assert(m <= a.size());
  assert(std::is_sorted(a.begin(), a.begin() + m));
  assert(std::is_sorted(a.begin() + m, a.end()));
  auto expected = a;

  inplace_merge(a.data(), m, a.size());
  std::inplace_merge(expected.begin(), expected.begin() + m, expected.end());

  assert(std::is_sorted(a.begin(), a.end()));
  assert(a == expected);
}


int main(int, char**)
{
  test_inplace_merge(std::vector<value_type>(), 0u);
  test_inplace_merge(std::vector<value_type> {1}, 0u);
  test_inplace_merge(std::vector<value_type> {1}, 1u);
  test_inplace_merge(std::vector<value_type> {1, 2, 3}, 0u);
  test_inplace_merge(std::vector<value_type> {1, 2, 3}, 3u);
  test_inplace_merge(std::vector<value_type> {2, 4, 6, 1, 3, 5}, 3u);
  test_inplace_merge(std::vector<value_type> {1, 3, 5, 2, 4, 6}, 3u);
  test_inplace_merge(std::vector<value_type> {4, 5, 6, 1, 2, 3}, 3u);
  test_inplace_merge(std::vector<value_type> {1, 1, 2, 1, 2, 2}, 3u);
  test_inplace_merge(std::vector<value_type> {7, 7, 7, 7, 7, 7}, 2u);

  // Two random halves, so that a failure can be reproduced from the seed.
  std::random_device r;
  const auto seed = r();
  std::mt19937 eng(seed);
  std::uniform_int_distribution<value_type> dist;
  auto generate = std::bind(dist, eng);
  size_type n = generate() % 100;
  size_type m = n == 0u ? 0u : generate() % (n + 1u);
  std::vector<value_type> a(n);
  std::generate(a.begin(), a.end(), generate);
  std::sort(a.begin(), a.begin() + m);
  std::sort(a.begin() + m, a.end());
  auto expected = a;

  inplace_merge(a.data(), m, n);
  std::inplace_merge(expected.begin(), expected.begin() + m, expected.end());

  if (!std::is_sorted(a.begin(), a.end()) || a != expected) {
    std::cerr << "inplace_merge failed for seed " << seed
              << ", length " << n << " and split " << m << '\n';
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
