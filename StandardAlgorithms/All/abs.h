
#include "limits.h"

/*@
    //requires x > INT_MIN;

    assigns \nothing;

    ensures x >= 0 ==> \result ==  x;
    ensures x <  0 ==> \result == -x;
*/
int abs(int x);


