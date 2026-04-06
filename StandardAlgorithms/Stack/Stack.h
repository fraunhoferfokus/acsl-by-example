
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "typedefs.h"

struct Stack {
  value_type*  data;
  size_type    cap;
  size_type    sz;
};

typedef struct Stack Stack;

#endif /* STACK_H_INCLUDED */

