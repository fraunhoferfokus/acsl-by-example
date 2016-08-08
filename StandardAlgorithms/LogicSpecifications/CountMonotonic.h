
#ifndef COUNTMONOTONIC_H_INCLUDED
#define COUNTMONOTONIC_H_INCLUDED

#include "CountLogic.h"
#include "CountSectionLemmas.h"

/*@
  lemma CountSectionMonotonic:
    \forall value_type *a, v, integer m, n, p;
       0 <= m <= n <= p ==>
         CountSection(a, m, n, v) <= CountSection(a, m, p, v);

  lemma CountMonotonic:
    \forall value_type *a, v, integer m, n;
      0 <= m <= n  ==> 
         Count(a, m, v) <= Count(a, n, v);
*/

#endif /* COUNTMONOTONIC_H_INCLUDED */

