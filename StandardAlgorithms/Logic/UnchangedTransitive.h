
#ifndef UNCHANGEDTRANSITIVE_H_INCLUDED
#define UNCHANGEDTRANSITIVE_H_INCLUDED

#include "Unchanged.h"

/*@
  lemma
    UnchangedTransitive{K,L,M}:
      \forall value_type *a, integer n;
        Unchanged{K,L}(a, n)  ==>
        Unchanged{L,M}(a, n)  ==>
        Unchanged{K,M}(a, n);
*/

#endif /* UNCHANGEDTRANSITIVE_H_INCLUDED */

