
#ifndef ACCUMULATE_H_INCLUDED
#define ACCUMULATE_H_INCLUDED

#include "AccumulateAxiomatic.h"
#include "limits.h"

/*@
    requires valid:  \valid_read(a + (0..n-1));
    requires bounds: \forall integer i; 0 <= i <= n ==>
                       INT_MIN <= Accumulate(a, i, init) <= INT_MAX;

    assigns \nothing;

    ensures result:  \result == Accumulate(a, n, init);
*/
value_type
accumulate(const value_type* a, size_type n, value_type init);

#endif /* ACCUMULATE_H_INCLUDED */

