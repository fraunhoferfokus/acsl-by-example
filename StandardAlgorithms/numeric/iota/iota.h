
#ifndef IOTA_H_INCLUDED
#define IOTA_H_INCLUDED

#include "IotaGenerate.acsl"
#include "limits.h"

/*@
  requires valid:    \valid(a + (0..n-1));
  requires limit:    val + n <= VALUE_TYPE_MAX;
  assigns            a[0..n-1];
  ensures increment: IotaGenerate(a, n, val);
*/
void
iota(value_type* a, size_type n, value_type val);

#endif /* IOTA_H_INCLUDED */

