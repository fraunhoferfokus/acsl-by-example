
#include "remove.h"
#include "../remove_copy/remove_copy.h"
#include "../../nonmutating/find2/find2.h"
#include "CountLemmas.h"
#include "CountShift.h"
#include "UnchangedShift.h"
#include "HasValueCountInversion.h"
#include "HasValueShiftInversion.h"


size_type remove(value_type* a, size_type n, value_type v)
{
  const size_type f = find(a, n, v);

  if (f == n) {

    //@ assert discard_nothing:  !HasValue(a, n, v);
    //@ assert size_zero:       Count{Pre}(a, n, v) == 0;
    return n;
  } else {

    const size_type m = remove_copy(a + f + 1, n - f - 1, a + f, v);

    //@ assert discard_first:  !HasValue(a, 0, f, v);
    //@ assert discard_remove: !HasValue(a+f, 0, m, v);
    //@ assert discard_remove: !HasValue(a, f, f+m, v);
    //@ assert discard_union:  !HasValue(a, f+m, v);

    //@ assert size_first:  1 == Count{Pre}(a, 0, f+1, v);
    //@ assert size_remove: m == n-f-1 - Count{Pre}(a, f+1, n, v);
    //@ assert size_union:  f+m == n - Count{Pre}(a, 0, n, v);

    //@ assert retain: MultisetRetainRest{Pre,Here}(a, f, a, f, v);
    //@ assert retain: MultisetRetainRest{Pre,Here}(a+f+1, n-f-1, a+f, m, v);
    //@ assert retain: MultisetRetainRest{Pre,Here}(a, n, a, f+m, v);

    //@ assert unchanged: Unchanged{Pre,Here}(a+f, m, n-f);
    //@ assert unchanged: Unchanged{Pre,Here}(a, f+m, n);
    return f + m;
  }
}

