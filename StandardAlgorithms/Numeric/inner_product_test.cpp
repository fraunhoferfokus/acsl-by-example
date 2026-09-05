
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <vector>

#include "inner_product.h"
#include "test_data.hpp"

void test_inner_product(const std::vector<value_type>& a,
                        const std::vector<value_type>& b, value_type init)
{
  assert(a.size() == b.size());

  const std::vector<value_type> a_before = a;
  const std::vector<value_type> b_before = b;

  assert(inner_product(a.data(), b.data(), a.size(), init) ==
         std::inner_product(a.begin(), a.end(), b.begin(), init));

  // The contract promises both arrays are left alone.
  assert(a == a_before);
  assert(b == b_before);
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    std::vector<value_type> zeros(a.size(), 0);
    std::vector<value_type> ones(a.size(), 1);
    std::vector<value_type> negated(a.size());

    for (size_type i = 0; i < a.size(); ++i) {
      negated[i] = -a[i];
    }

    test_inner_product(a, zeros, 0);
    test_inner_product(a, ones, 0);
    test_inner_product(a, ones, 5);
    test_inner_product(a, negated, 0);
    test_inner_product(a, a, 0);
  }

  test_inner_product({1, 3, -6, 0, 4}, {2, 15, 9, -3, 0}, 2);

  return EXIT_SUCCESS;
}
