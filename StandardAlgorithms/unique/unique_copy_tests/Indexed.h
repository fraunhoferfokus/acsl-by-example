
#ifndef INDEXEDPAIR_H_INCLUDED
#define INDEXEDPAIR_H_INCLUDED

#include <utility>
#include <cstddef>

template<typename T>
struct Indexed : public std::pair<T, size_t> {

  // inherit constructors of base class
  using std::pair<T, size_t>::pair;

};

template<typename T>
bool operator==(const Indexed<T>& a, const Indexed<T>& b)
{
  return a.first == b.first;
}

#include "Indexed_io.h"

#endif /* INDEXEDPAIR_H_INCLUDED */

