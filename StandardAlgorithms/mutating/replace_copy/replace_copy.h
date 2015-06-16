
#ifndef REPLACE_COPY_H_INCLUDED
#define REPLACE_COPY_H_INCLUDED

#include "typedefs.h"

/*@
  requires valid_a: \valid_read(a + (0..n-1));
  requires valid_b:      \valid(b + (0..n-1));
  requires sep:      \separated(a + (0..n-1), b + (0..n-1));

  assigns b[0..n-1];

  ensures change: \forall integer i; 0 <= i < n
              ==> (\old(a[i]) == oldv ==> b[i] == newv);

  ensures keep:   \forall integer i; 0 <= i < n
              ==> (\old(a[i]) != oldv ==> b[i] == \old(a[i]));

  ensures result: \result == n;
*/
size_type replace_copy(const value_type* a, size_type n,
                       value_type* b,
                       value_type  oldv, value_type newv);

#endif /* REPLACE_COPY_H_INCLUDED */

