
#ifndef INDEXEDPAIR_IO_H_INCLUDED
#define INDEXEDPAIR_IO_H_INCLUDED

#include <iostream>
#include "Indexed.h"

template<typename T>
std::ostream& operator<<(std::ostream& stream, const Indexed<T>& p)
{
  stream << '(' << p.first << ',' << p.second << ')';

  return stream;
}

template<typename T>
std::istream& operator>>(std::istream& stream, Indexed<T>& p)
{
  if (stream.good()) {
    ws(stream);
    if (stream.peek() == '(') {
      stream.get();
      T t;
      stream >> t;
      if (!stream.fail()) {
        ws(stream);
        auto c = stream.peek();
        if (c == ',') {
          stream.get();
          size_t i;
          stream >> i;
          if (!stream.fail()) {
            ws(stream);
            c = stream.peek();
            if (c == ')') {
              stream.get();
              p = Indexed<T>(t, i);
            }
            else {
              stream.setstate(std::ios_base::failbit);
            }
          }
          else {
            stream.setstate(std::ios_base::failbit);
          }
        }
      }
      else {
        stream.setstate(std::ios_base::failbit);
      }
    }
  }
  else {
    stream.setstate(std::ios_base::failbit);
  }

  return stream;
}


#endif /* INDEXEDPAIR_IO_H_INCLUDED */

