
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "binary_search.h"
#include "partitioned_test.h"

// binary_search decides whether v occurs in an increasing array. The earlier
// test asked about one value that did occur.
void test_binary_search(const std::vector<value_type>& a, value_type v)
{
  assert(std::is_sorted(a.begin(), a.end()));

  const bool expected = std::binary_search(a.begin(), a.end(), v);

  assert(binary_search(a.data(), a.size(), v) == expected);
  assert(expected == (std::find(a.begin(), a.end(), v) != a.end()));
}


int main(int, char**)
{
  const std::vector<value_type> a = binary_search_data();   // {2,3,3,3,8,8,11,14,14}

  test_binary_search(a, 1);     // below every element
  test_binary_search(a, 2);     // the first element
  test_binary_search(a, 3);     // occurs three times
  test_binary_search(a, 5);     // between two elements
  test_binary_search(a, 8);     // occurs twice
  test_binary_search(a, 11);    // occurs once, in the middle
  test_binary_search(a, 14);    // the last element
  test_binary_search(a, 17);    // above every element

  // The degenerate arrays every contract admits.
  test_binary_search({}, 3);
  test_binary_search({3}, 3);
  test_binary_search({3}, 2);
  test_binary_search({3}, 4);
  test_binary_search({3, 3, 3}, 3);
  test_binary_search({1, 2}, 1);
  test_binary_search({1, 2}, 2);

  return EXIT_SUCCESS;
}
