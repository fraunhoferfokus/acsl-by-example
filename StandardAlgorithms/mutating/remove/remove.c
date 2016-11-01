
#include "remove.h"
#include "../remove_copy/remove_copy.h"
#include "../../nonmutating/find2/find2.h"
#include "CountLemmas.h"
#include "CountShift.h"
#include "HasValueCountInversion.h"
#include "HasValueShiftInversion.h"


size_type remove(value_type* a, size_type n, value_type v)
{
  size_type first = find(a, n, v);

  if (first == n) {

    //@ assert discard_nothing:  !HasValue(a, n, v);
    //@ assert size_zero:       Count{Pre}(a, n, v) == 0;
    return n;
  } else {

    size_type m = remove_copy(a + first + 1, n - first - 1, a + first, v);

    //@ assert discard_first:  !HasValue(a, 0, first, v);
    //@ assert discard_remove: !HasValue(a + first, 0, m, v);
    //@ assert discard_remove: !HasValue(a, first, first + m, v);
    //@ assert discard_union:  !HasValue(a, first + m, v);

    //@ assert size_first:  1 == Count{Pre}(a, 0, first + 1, v);
    //@ assert size_remove: m == n - first - 1 - Count{Pre}(a, first + 1, n, v);
    //@ assert size_union:  first + m == n - Count{Pre}(a, 0, n, v);

    //@ assert retain:    MultisetRetainRest{Pre,Here}(a, n, a, first + m, v);
    //@ assert unchanged: Unchanged{Pre,Here}(a, first + m, n);
    return first + m;
  }
}

