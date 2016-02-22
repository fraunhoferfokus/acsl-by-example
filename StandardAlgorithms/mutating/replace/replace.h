
#ifndef REPLACE_COPY_H_INCLUDED
#define REPLACE_COPY_H_INCLUDED

#include "ReplaceLogic.h"
#include "Unchanged.h"

/*@
  requires valid: \valid(a + (0..n-1));

  assigns a[0..n-1];

  ensures replace:  Replace{Old,Here}(a, n, oldv, newv);
*/
void replace(value_type* a, size_type n, value_type oldv, value_type newv);

#endif /* REPLACE_COPY_H_INCLUDED */

