
#include "stack.h"
#include <assert.h>
#include <stdio.h>


int main()
{
  value_type a[1];

  Stack s;
  stack_init(&s, a, 1);

  value_type b[2];
  Stack t;
  stack_init(&t, b, 2);

  // after init
  assert(stack_equal(&s, &t));
  assert(stack_empty(&s));
  assert(stack_empty(&t));
  assert(!stack_full(&s));
  assert(!stack_full(&t));

  stack_push(&s, 7);
  stack_push(&t, 7);
  assert(stack_equal(&s, &t));
  assert(stack_full(&s));
  assert(!stack_full(&t));

  printf("done\n");
  return EXIT_SUCCESS;
}




