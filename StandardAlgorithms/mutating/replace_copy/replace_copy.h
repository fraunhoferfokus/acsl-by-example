
#ifndef REPLACE_COPY_H_INCLUDED
#define REPLACE_COPY_H_INCLUDED

#include "ReplaceLogic.h"
#include "Unchanged.h"

/*@
  requires valid:  \valid_read(a + (0..n-1));
  requires valid:       \valid(b + (0..n-1));
  requires sep:     \separated(a + (0..n-1), b );

  assigns b[0..n-1];

  ensures replace:   Replace{Old,Here}(a, n, b, v, w);
  ensures result:    \result == n;
*/
size_type
replace_copy(const value_type* a, size_type n, value_type* b,
             value_type v, value_type w);

#endif /* REPLACE_COPY_H_INCLUDED */

