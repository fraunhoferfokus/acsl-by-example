
#ifndef ADJACENT_DIFFERENCE_H_INCLUDED
#define ADJACENT_DIFFERENCE_H_INCLUDED

#include "AdjacentDifference.h"
#include "AdjacentDifferenceBounds.h"

/*@
   requires valid:      \valid_read(a + (0..n-1));
   requires valid:      \valid(b + (0..n-1));
   requires separated:  \separated(a + (0..n-1), b + (0..n-1));
   requires bounds:     AdjacentDifferenceBounds(a, n);

   assigns b[0..n-1];

   ensures result:      \result == n;
   ensures difference:  AdjacentDifference(a, n, b);
   ensures unchanged:   Unchanged{Here,Old}(a, n);
*/
size_type
adjacent_difference(const value_type* a, size_type n, value_type* b);

#endif /* ADJACENT_DIFFERENCE_H_INCLUDED */

