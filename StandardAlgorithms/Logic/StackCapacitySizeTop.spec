
#ifndef STACKCAPACITYSIZETOP_SPEC_INCLUDED
#define STACKCAPACITYSIZETOP_SPEC_INCLUDED

#include "stack.h"

/*@
  logic integer Capacity{L}(Stack* s) = s->capacity;

  logic integer Size{L}(Stack* s) = s->size;

  logic value_type* Storage{L}(Stack* s) = s->obj;

  logic integer Top{L}(Stack* s) = s->obj[s->size-1];
*/

#endif /* STACKCAPACITYSIZETOP_SPEC_INCLUDED */

