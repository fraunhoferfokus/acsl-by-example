
#ifndef FIND_TEST_HPP_INCLUDED
#define FIND_TEST_HPP_INCLUDED

#include <algorithm>
#include <cassert>
#include <vector>

#include "test_data.hpp"

// The five find variants share one contract: the index of the first
// occurrence of v, or n if v does not occur. The five tests therefore share
// one check, which is run for every value that occurs in each test array and
// for two that occur in none of them.
//
// Note that the check compares indices only. Asserting *it == a[pos], as
// these tests once did, is undefined as soon as v is absent: it is then
// end() and pos is n.
template<class Find>
void check_find(Find find_function)
{
  for (const auto& a : test_arrays()) {
    std::vector<value_type> values = a;
    values.push_back(present_value());
    values.push_back(absent_value());

    for (const value_type v : values) {
      const auto it = std::find(a.begin(), a.end(), v);
      const size_type expected = static_cast<size_type>(it - a.begin());

      assert(find_function(a.data(), a.size(), v) == expected);
    }
  }
}

#endif /* FIND_TEST_HPP_INCLUDED */
