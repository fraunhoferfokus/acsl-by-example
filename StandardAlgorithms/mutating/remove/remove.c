
#include "remove.h"
#include "../remove_copy/remove_copy.h"
#include "../../nonmutating/find2/find2.h"
#include "CountShift.h"
#include "UnchangedShift.h"
#include "HasValueImpliesPositiveCount.h"
#include "PositiveCountImpliesHasValue.h"

size_type remove(value_type* a, size_type n, value_type v)
{
  const size_type f = find(a, n, v);
  //@ assert discard: !HasValue(a, 0, f, v);

  if (f < n) {
    //@ assert size:  1 == Count{Pre}(a, 0, f+1, v);

    /*@
      assigns            m, a[f..n-1];
      ensures bound:     0 <= m <= n-f-1;
      ensures size:      m == n-f-1 - Count{Old}(a+f+1, n-f-1, v);
      ensures retain:    MultisetRetainRest{Old,Here}(a+f+1, n-f-1, a+f, m, v);
      ensures discard:   !HasValue(a+f, 0, m, v);
      ensures unchanged: Unchanged{Old,Here}(a+f, m, n-f);
      ensures unchanged: Unchanged{Old,Here}(a, 0, f);
    */
    const size_type m = remove_copy(a + f + 1u, n - f - 1u, a + f, v);

    //@ assert discard:   !HasValue(a, f, f+m, v);
    //@ assert discard:   !HasValue(a, f+m, v);
    //@ assert size:      f+m == n - Count{Pre}(a, 0, n, v);
    //@ assert retain:    MultisetRetainRest{Pre,Here}(a, 0, f, a, 0, f, v);
    //@ assert retain:    MultisetRetainRest{Pre,Here}(a, f, n, a, f, f+m, v);
    //@ assert retain:    MultisetRetainRest{Pre,Here}(a, n, a, f+m, v);
    //@ assert unchanged: Unchanged{Pre,Here}(a, f+m, n);
    return f + m;
  }
  else {
    //@ assert discard: !HasValue(a, n, v);
    //@ assert size:    0 == Count{Pre}(a, n, v);
    return n;
  }
}

