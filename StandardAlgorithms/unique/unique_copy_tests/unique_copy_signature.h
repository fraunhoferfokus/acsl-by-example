
#ifndef UNIQUE_COPY_SIGNATURE_TEST_H_INCLUDED
#define UNIQUE_COPY_SIGNATURE_TEST_H_INCLUDED

#include "../../typedefs.h"

#ifdef UNIQUE_COPY_GENERIC

#include <algorithm>

template<typename T>
size_t unique_copy(const T* a, size_t n, T* b)
{
  auto result = std::unique_copy(a, a + n, b);
  return result - b;
}

#else

extern size_type
unique_copy(const value_type* a, size_type n, value_type* b);

#endif /*UNIQUE_COPY_SIGNATURE_TEST_H_INCLUDED */

#endif /*UNIQUE_COPY_SIGNATURE_TEST_H_INCLUDED */

