/*@ requires valid: \valid_read(a + (0 .. n - 1));
    requires valid: \valid(b + (0 .. n - 1));
    requires sep: \separated(a + (0 .. n - 1), b + (0 .. n - 1));
    ensures result: 0 <= \result <= \old(n);
    ensures unchanged: Unchanged{Old, Here}(\old(b), \result, \old(n));
    assigns *(b + (0 .. n - 1));
 */
size_type
unique_copy2(value_type const *a, size_type n, value_type *b)
{
  size_type __retres;

  if (n == 0u) {
    __retres = n;
    goto return_label;
  }
  else {
    size_type k = 0u;
    /*@ assert rte: mem_access: \valid(b + k); */
    /*@ assert rte: mem_access: \valid_read(a + 0); */
    *(b + k) = *(a + 0);
    {
      size_type i = 1u;

      /*@ loop invariant bound: 0 <= k < i <= n;
          loop invariant unchanged: Unchanged{Pre, Here}(b, k + 1, n);
          loop assigns i, k, *(b + (0 .. n - 1));
          loop variant n - i;
      */
      while (i < n) {
        {
          /*@ assert rte: mem_access: \valid_read(a + i); */
          value_type const val = *(a + i);

          /*@ assert rte: mem_access: \valid_read(b + k); */
          if (*(b + k) != val) {
            /*@ assert rte: unsigned_overflow: k + 1 <= 4294967295; */
            k ++;
            /*@ assert rte: mem_access: \valid(b + k); */
            *(b + k) = val;
          }
        }
        /*@ assert rte: unsigned_overflow: i + 1 <= 4294967295; */
        i ++;
      }
    }
    /*@ assert rte: unsigned_overflow: k + 1 <= 4294967295; */
    k ++;
    __retres = k;
    goto return_label;
  }

return_label:
  return __retres;
}


