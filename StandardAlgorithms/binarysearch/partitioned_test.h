
#ifndef PARTITIONED_TEST_H_INCLUDED
#define PARTITIONED_TEST_H_INCLUDED

#include "typedefs.h"
#include <vector>
#include <algorithm>
#include <functional>

inline 
std::vector<value_type> binary_search_data()
{
  return std::vector<value_type>{2, 3, 3, 3, 8, 8, 11, 14, 14};
}

template<typename It, typename Pred>
void partitioned_test(It first, It middle, It last, Pred pred)
{
  assert(std::all_of(first, middle, pred));
  assert(std::none_of(middle, last, pred));
}

#endif // PARTITIONED_TEST_H_INCLUDED

