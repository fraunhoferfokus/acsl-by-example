
#ifndef SWAP_RANGES_H_INCLUDED
#define SWAP_RANGES_H_INCLUDED

#include "EqualRanges.h"
#include "Unchanged.h"

/*@
  requires valid_a: \valid(a + (0..n-1));
  requires valid_a: \valid(b + (0..n-1));
  requires sep:     \separated(a+(0..n-1), b+(0..n-1));

  assigns a[0..n-1];
  assigns b[0..n-1];

  ensures equal_a: EqualRanges{Here,Old}(a, n, b);
  ensures equal_b: EqualRanges{Old,Here}(a, n, b);
*/
void swap_ranges(value_type* a, size_type n, value_type* b);

#endif /* SWAP_RANGES_H_INCLUDED */

