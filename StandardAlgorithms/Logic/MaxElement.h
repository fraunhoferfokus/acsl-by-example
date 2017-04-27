
#ifndef MAXELEMENT_H_INCLUDED
#define MAXELEMENT_H_INCLUDED

#include "UpperBound.h"

/*@
  predicate
    MaxElement{L}(value_type* a, integer n, integer max) =
      0 <= max < n && UpperBound(a, n, a[max]);
*/

#endif /* MAXELEMENT_H_INCLUDED */

