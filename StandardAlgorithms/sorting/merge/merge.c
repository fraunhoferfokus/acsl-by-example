
#include "merge.h"
#include "copy.h"

void
merge(const value_type* a, size_type n,
      const value_type* b, size_type m,
      value_type* result)
{
  size_type i = 0;
  size_type j = 0;
  size_type x = 0;

  if (n == 0 && m == 0) {
    return;
  }

  /*@ loop invariant 0 <= i <= n;
      loop invariant 0 <= j <= m;
      loop invariant x == i + j;
      loop invariant 0 <= x <= n + m - 1;
      loop invariant order:  \forall integer k; 0 <= k < x && i < n ==>
                                 result[k] <= a[i];
      loop invariant order:  \forall integer k; 0 <= k < x && j < m ==>
                                 result[k] <= b[j];
      loop invariant sorted: WeaklySorted(result, x);
      loop assigns i, j, x, result[0 .. n+m-1];
      loop variant (n + m) - (i + j);
   */
  while (i < n && j < m) {
    if (a[i] < b[j]) {
      result[x++] = a[i++];
    }
    else {
      result[x++] = b[j++];
    }
  }

  //@ assert i == n ^^ j == m;
  //@ assert i < n ^^ j < m;
  //@ assert WeaklySorted(result, 0, x);

  if (i < n) {
    //@ assert 0 < x ==> result[x-1] <= a[i];
    //@ assert WeaklySorted(a + i, 0, n - i);
    copy(a + i, n - i, result + x);
    //@ assert result[x] == a[i];
    /*@ assert WeaklySorted(a + i, 0, n - i) &&
               EqualRanges{Here,Here}(a + i, 0, n - i, result + x) ==>
                  WeaklySorted(result + x, 0, n - i);
     */
    //@ assert n - i + x == n + m;
  }
  else {
    //@ assert 0 < x ==> result[x-1] <= b[j];
    //@ assert WeaklySorted(b + j, 0, m - j);
    copy(b + j, m - j, result + x);
    //@ assert result[x] == b[j];
    /*@ assert WeaklySorted(b + j, 0, m - j) &&
               EqualRanges{Here,Here}(b + j, 0, m - j, result + x) ==>
                  WeaklySorted(result + x, 0, m - j);
     */
    //@ assert m - j + x == n + m;
  }

  //@ assert WeaklySorted(result, x, n + m);
  //@ assert x > 0 ==> result[x-1] <= result[x];
  //@ assert WeaklySorted(result, 0, n + m);
}

