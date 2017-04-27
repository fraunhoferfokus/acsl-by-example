
#ifndef HASVALUEOF_H_INCLUDED
#define HASVALUEOF_H_INCLUDED

#include "HasValue.h"

/*@
  predicate
    HasValueOf{A}(value_type* a, integer m, value_type* b, integer n) =
      \exists integer i; 0 <= i < m && HasValue{A}(b, n, a[i]);
*/

#endif /* HASVALUEOF_H_INCLUDED */

