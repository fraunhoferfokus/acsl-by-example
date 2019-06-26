
#ifndef UNIQUE_COPY_SHRINK__INCLUDED
#define UNIQUE_COPY_SHRINK__INCLUDED

#include <vector>
#include "unique_copy_signature.h"

template<typename T>
std::vector<T>
unique_copy(const std::vector<T>& a)
{
  std::vector<T> b(a.size());

  auto size = unique_copy(a.data(), a.size(), b.data());
  b.resize(size);

  return b;
}


#endif /*UNIQUE_COPY_SHRINK__INCLUDED */

