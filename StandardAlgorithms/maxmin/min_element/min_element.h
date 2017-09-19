
#ifndef MIN_ELEMENT_H_INCLUDED
#define MIN_ELEMENT_H_INCLUDED

#include "MinElement.h"
#include "StrictLowerBound.h"

/*@
  requires valid:   \valid_read(a + (0..n-1));
  assigns  \nothing;
  ensures  result:  0 <= \result <= n;

  behavior empty:
    assumes n == 0;
    ensures result:  \result == 0;

  behavior not_empty:
    assumes 0 < n;
    ensures result:  0 <= \result < n;
    ensures min:     MinElement(a, n, \result);
    ensures strict:  StrictLowerBound(a, \result, a[\result]);

  complete behaviors;
  disjoint behaviors;
*/
size_type min_element(const value_type* a, size_type n);

#endif /* MIN_ELEMENT_H_INCLUDED */

