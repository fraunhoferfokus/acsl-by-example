
#ifndef DIFFERENCE_H_INCLUDED
#define DIFFERENCE_H_INCLUDED

#include "Unchanged.h"

/*@
   axiomatic DifferenceAxiomatic 
   {
      logic value_type
      Difference{L}(value_type* a, integer n) reads a[0..n]; 

      axiom
        DifferenceEmptyOrSingle{L}:
          \forall value_type *a, integer n;
            n <= 0 ==> Difference(a, n) == a[0];

      axiom
        DifferenceNext{L}:
          \forall value_type *a, integer n;
            0 < n ==> Difference(a, n) == a[n] - a[n-1];

      axiom
        DifferenceRead{K,L}:
          \forall value_type *a, integer n;
            Unchanged{K,L}(a, 1+n) ==> Difference{K}(a, n) == Difference{L}(a, n);
   }
*/

#endif /* DIFFERENCE_H_INCLUDED */

