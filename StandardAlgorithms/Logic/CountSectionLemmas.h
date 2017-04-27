
#ifndef COUNTSECTIONLEMMAS_H_INCLUDED
#define COUNTSECTIONLEMMAS_H_INCLUDED

#include "CountSection.h"

/*@
  lemma CountSectionOne:
    \forall value_type *a, v, integer m, n;
      m <= n  ==>
        Count(a, m, n+1, v) == Count(a, m, n, v) + Count(a, n, n+1, v);


  lemma CountSectionUnion:
    \forall value_type *a, v, integer m, n;
      0 <= m <= n  ==>
        Count(a, 0, n, v) == Count(a, 0, m, v) + Count(a, m, n, v);
*/

#endif /* COUNTSECTIONLEMMAS_H_INCLUDED */

