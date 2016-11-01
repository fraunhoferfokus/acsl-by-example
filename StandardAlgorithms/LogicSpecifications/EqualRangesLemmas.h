
#ifndef EQUALRANGESLEMMAS_H_INCLUDED
#define EQUALRANGESLEMMAS_H_INCLUDED

/*@ lemma EqualRangesUnion{A,B}:
      \forall value_type *a, *b, integer p, q, r;
        p <= q <= r &&
        EqualRanges{A,B}(a, p, q, b) &&
	EqualRanges{A,B}(a, q, r, b) ==>
	EqualRanges{A,B}(a, p, r, b);
*/

#endif /* EQUALRANGESLEMMAS_H_INCLUDED */

