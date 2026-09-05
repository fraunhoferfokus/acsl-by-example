
#ifndef IS_SORTED_UNTIL_H_INCLUDED
#define IS_SORTED_UNTIL_H_INCLUDED

#include "Increasing.acsl"

/*@
  requires   valid:       \valid_read(a + (0..n-1));

  terminates              \true;
  exits                   \false;
  assigns                 \nothing;

  ensures    bound:       0 <= \result <= n;
  ensures    increasing:  Increasing(a, \result);
  ensures    last:        \result < n  ==>  !Increasing(a, \result + 1);
*/
size_type is_sorted_until(const value_type* a, size_type n);

#endif /* IS_SORTED_UNTIL_H_INCLUDED */

