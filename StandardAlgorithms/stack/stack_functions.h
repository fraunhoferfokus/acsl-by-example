
#ifndef STACK_FUNCTIONS_H_INCLUDED
#define STACK_FUNCTIONS_H_INCLUDED

#include "stack_definition.h"

void        stack_init(Stack* s, value_type* a, size_type n);

bool        stack_equal(const Stack* s, const Stack* t);

size_type   stack_size(const Stack* s);

bool        stack_empty(const Stack* s);

bool        stack_full(const Stack* s);

value_type  stack_top(const Stack* s);

void        stack_push(Stack* s, value_type v);

void        stack_pop(Stack* s);

#endif /* STACK_FUNCTIONS_H_INCLUDED */

