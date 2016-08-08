
#ifndef COUNTSECTIONLEMMAS_H_INCLUDED
#define COUNTSECTIONLEMMAS_H_INCLUDED

#include "CountSection.h"

/*@
  lemma CountSectionOne:
    \forall value_type *a, v, integer m, n;
      CountSection(a, m, n + 1, v) ==
        CountSection(a, m, n, v) + CountSection(a, n, n+1, v);

  lemma CountSectionUnion:
    \forall value_type *a, v, integer m, n;
      0 <= m <= n ==>
        CountSection(a, 0, n, v) ==
          CountSection(a, 0, m, v) + CountSection(a, m, n, v);
*/

#endif /* COUNTSECTIONLEMMAS_H_INCLUDED */

