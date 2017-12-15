
#ifndef UNCHANGEDSECTION_H_INCLUDED
#define UNCHANGEDSECTION_H_INCLUDED

#include "Unchanged.h"

/*@
  lemma
    UnchangedSection{K,L}:
      \forall value_type *a, integer m, n, p, q;
         0 <= m <= p <= q <= n    ==>
         Unchanged{K,L}(a, m, n)  ==> 
         Unchanged{K,L}(a, p, q);
*/

#endif /* UNCHANGEDSECTION_H_INCLUDED */

