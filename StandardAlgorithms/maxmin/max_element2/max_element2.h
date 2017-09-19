
#ifndef MAX_ELEMENT2_H_INCLUDED
#define MAX_ELEMENT2_H_INCLUDED

#include "MaxElement.h"
#include "StrictUpperBound.h"

/*@
  requires valid:    \valid_read(a + (0..n-1));
  assigns  \nothing;
  ensures  result:   0 <= \result <= n;

  behavior empty:
    assumes n == 0;
    ensures result:   \result == 0;

  behavior not_empty:
    assumes 0 < n;
    ensures result:   0 <= \result < n;
    ensures max:      MaxElement(a, n, \result);
    ensures strict:   StrictUpperBound(a, \result, a[\result]);

  complete behaviors;
  disjoint behaviors;
*/
size_type max_element(const value_type* a, size_type n);

#endif /* MAX_ELEMENT2_H_INCLUDED */
