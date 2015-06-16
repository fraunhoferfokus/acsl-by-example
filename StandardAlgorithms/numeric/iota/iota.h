
#ifndef IOTA_H_INCLUDED
#define IOTA_H_INCLUDED

#include "typedefs.h"
#include "limits.h"

/*@
  requires valid:  \valid(a + (0..n-1));
  requires limit1: n <= INT_MAX;
  requires limit2: val + n <= INT_MAX;

  assigns a[0..n-1];

  ensures increment: \forall integer k; 0 <= k < n
                     ==> a[k] == val + k;
*/
void iota(value_type* a, size_type n, value_type val);

#endif /* IOTA_H_INCLUDED */

