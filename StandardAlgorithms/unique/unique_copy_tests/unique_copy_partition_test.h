
#ifndef UNIQUE_COPY_PARTITION_TEST_H_INCLUDED
#define UNIQUE_COPY_PARTITION_TEST_H_INCLUDED

#include <cassert>
#include "unique_copy_create_partition.h"

template<typename T>
void unique_copy_partition_test(const std::vector<T>& a)
{
  auto b = unique_copy(a);
  auto unzipped = unique_copy_create_partition(a);
  assert(unzipped.first == b);

  const std::vector<size_t>& p = unzipped.second;

  // partition sequence is one element longer than output array
  assert(p.size() == b.size() + 1);

  // monotonicity (first and last element only)
  assert(p.front() == 0);
  assert(p.back()  == a.size());

  for (size_t i = 0; i < b.size(); ++i) {
    // consider i-th segment of the partition
    auto begin = p[i];
    auto end   = p[i + 1];

    // monotonicity
    assert(begin < end);

    // consecutive range of equal elements
    for (size_t k = begin; k < end; ++k) {
      assert(a[begin] == a[k]);
    }

    // maximal consecutive range of equal elements
    if (i + 1 < b.size()) {
      assert(a[begin] != a[end]);
    }

    // result of unique_copy
    assert(b[i] == a[begin]);
  }
}

#endif /* UNIQUE_COPY_PARTITION_TEST_H_INCLUDED */

