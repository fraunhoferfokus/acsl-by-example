
#ifndef IS_SORTED_H_INCLUDED
#define IS_SORTED_H_INCLUDED

#include "Sorted.spec"

/*@
  requires valid: \valid_read(a + (0..n-1));

  assigns  \nothing;

  ensures  \result <==> Sorted(a, n);
*/
bool
is_sorted(const value_type* a, size_type n);

#endif /* IS_SORTED_H_INCLUDED */

