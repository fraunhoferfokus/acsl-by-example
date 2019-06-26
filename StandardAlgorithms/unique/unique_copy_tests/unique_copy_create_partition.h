
#ifndef UNIQUE_COPY_CREATE_PARTITION_H_INCLUDED
#define UNIQUE_COPY_CREATE_PARTITION_H_INCLUDED

#include "Indexed.h"
#include "unique_copy_vector.h"
#include "vector_io.h"

template<typename T>
std::pair<std::vector<T>, std::vector<size_t>>
    unique_copy_create_partition(const std::vector<T>& input)
{
  std::vector<Indexed<T>> zipped(input.size());
  for (size_t i = 0; i < input.size(); i++) {
    zipped[i] = Indexed<T>(input[i], i);
  }

  auto output = unique_copy(zipped);

  std::pair<std::vector<T>, std::vector<size_t>> unzipped;
  unzipped.first.resize(output.size());
  unzipped.second.resize(output.size() + 1);

  for (size_t i = 0; i < output.size(); ++i) {
    unzipped.first[i]  = output[i].first;
    unzipped.second[i] = output[i].second;
  }
  unzipped.second.back() = input.size();

  return unzipped;
}


#endif /* UNIQUE_COPY_CREATE_PARTITION_H_INCLUDED */

