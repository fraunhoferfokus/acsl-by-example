
#ifndef UNIQUE_COPY_COMPARE_TEST_H_INCLUDED
#define UNIQUE_COPY_COMPARE_TEST_H_INCLUDED

#include "unique_copy_basic_test.h"

template<typename T>
void
unique_copy_compare_test(const std::vector<T>& input,
                         const std::vector<T>& expected)
{
  auto result = unique_copy_basic_test<T>(input);
  assert(result == expected);

  //std::cout << "test " << __func__ << " succeeded " << std::endl;
}

#endif /* UNIQUE_COPY_COMPARE_TEST_H_INCLUDED */

