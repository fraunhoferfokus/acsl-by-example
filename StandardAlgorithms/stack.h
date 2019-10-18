
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "typedefs.h"

struct Stack
{
  value_type* obj;

  size_type   capacity;

  size_type   size;
};

typedef struct Stack Stack;

#endif /* STACK_H_INCLUDED */

