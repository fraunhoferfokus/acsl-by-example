
#ifndef UNIQUE_COPY_BASIC_TEST_H_INCLUDED
#define UNIQUE_COPY_BASIC_TEST_H_INCLUDED

#include <algorithm>
#include <cassert>
#include <iostream>
#include "vector_io.h"
#include "unique_copy_vector.h"

template<typename T>
std::vector<T>
unique_copy_basic_test(const std::vector<T>& input)
{
  auto result = unique_copy(input);
  assert(std::adjacent_find(result.begin(), result.end()) == result.end());

  //std::cout << "test " << __func__ << " succeeded " << std::endl;

  return result;
}

#endif /*UNIQUE_COPY_BASIC_TEST_H_INCLUDED */

