
#ifndef UNCHANGEDSHIFT_H_INCLUDED
#define UNCHANGEDSHIFT_H_INCLUDED

#include "Unchanged.h"

/*@
  lemma
    UnchangedShift{K,L}:
      \forall value_type *a, integer p, q, r;
        Unchanged{K,L}(a+p, q, r) ==> Unchanged{K,L}(a, p+q, p+r);
*/

#endif /* UNCHANGEDSHIFT_H_INCLUDED */

