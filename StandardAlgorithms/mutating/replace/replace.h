
#ifndef REPLACE_COPY_H_INCLUDED
#define REPLACE_COPY_H_INCLUDED

#include "Replace.spec"
#include "Unchanged.spec"

/*@
  requires valid:   \valid(a + (0..n-1));
  assigns           a[0..n-1];
  ensures replace:  Replace{Old,Here}(a, n, v, w);
*/
void
replace(value_type* a, size_type n, value_type v, value_type w);

#endif /* REPLACE_COPY_H_INCLUDED */

