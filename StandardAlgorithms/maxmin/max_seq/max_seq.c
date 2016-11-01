
#include "max_seq.h"

value_type max_seq(const value_type* p, size_type n)
{
  return p[max_element(p, n)];
}

