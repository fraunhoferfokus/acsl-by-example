
#ifndef VECTOR_IO_H_INCLUDED
#define VECTOR_IO_H_INCLUDED

#include <iostream>
#include <vector>
#include <iterator>

template<typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& v)
{
    stream << '(';
    for(auto i = v.begin(); i != v.end(); ++i) {
        stream << *i <<  ((std::next(i) != v.end()) ? ',' : ')');
    }

    return stream;
}

#endif /* VECTOR_IO_H_INCLUDED */

