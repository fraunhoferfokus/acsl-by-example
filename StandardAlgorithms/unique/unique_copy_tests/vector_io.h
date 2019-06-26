
#ifndef VECTOR_IO_H_INCLUDED
#define VECTOR_IO_H_INCLUDED

#include <vector>
#include <iostream>

template<typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& v)
{
  stream << '(';
  for (size_t i = 0; i < v.size(); i++) {
    stream << v[i];

    if (i + 1 < v.size()) {
      stream << ',';
    }
  }
  stream << ')';

  return stream;
}

template<typename T>
std::istream& operator>>(std::istream& stream, std::vector<T>& v)
{
  if (stream.good()) {
    ws(stream);
    if (stream.peek() == '(') {
      stream.get();

      std::vector<T> tmp;
      while (stream.good()) {
        if (stream.peek() == ')') {
          stream.get();
          break;
        }
        else {
          T t;
          stream >> t;
          tmp.push_back(t);
          if (!stream.fail()) {
            ws(stream);
            auto c = stream.peek();
            if (c == ',') {
              stream.get();
              continue;
            }
            else if (c == ')') {
              stream.get();
              break;
            }
          }
        }
      }

      v = std::move(tmp);
    }
    else {
      stream.setstate(std::ios_base::failbit);
    }
  }

  return stream;
}


#endif /* VECTOR_IO_H_INCLUDED */

