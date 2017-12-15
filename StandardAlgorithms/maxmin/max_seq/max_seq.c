
#include "max_seq.h"
#include "../max_element2/max_element2.h"

value_type max_seq(const value_type* p, size_type n)
{
  return p[max_element(p, n)];
}

