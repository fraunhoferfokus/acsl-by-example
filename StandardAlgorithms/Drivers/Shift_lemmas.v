
Require Import ZArith.
Require Import Memory.
Require Import Qedlib.
Require Import Psatz.

Open Scope Z_scope.

Lemma cdiv_lower :
  forall a b, 0 <= a -> 0 < b ->  0 <= (Cdiv a b).
Proof.
  intros.
  replace (Cdiv a b) with (a/b).
  - apply Z_div_pos; lia.
  - destruct Cdiv_cases with (a) (b); lia.
Qed.

Lemma cdiv_upper :
  forall a b, 0 <= a -> 1 < b ->  (Cdiv a b) <= a.
Proof.
  intros.
  replace (Cdiv a b) with (a/b).
  - assert(zero_pos: 0 = a \/ 0 < a) by lia.
    destruct zero_pos as [zero|pos].
    + rewrite <- zero.
      rewrite Zdiv_0_l; lia.
    + enough (a/b < a) by lia.
      apply Z_div_lt; lia.
  - destruct Cdiv_cases with (a) (b); lia.
Qed.

Lemma shift_associative :
  forall a, forall m n,
    shift (shift a m) n = shift a (m + n).
Proof.
  intros.
  unfold shift; cbn.
  replace (offset a + m + n) with (offset a + (m + n)) by lia.
  trivial.
Qed.


Lemma addr_neq_symmetry :
   forall a b: addr, a <> b -> b <> a.
Proof.
  intros.
  intuition.
Qed.


Lemma shift_zero :
   forall a, (shift a 0) = a.
Proof.
  intros a. 
  unfold shift.
  replace (offset a + 0) with (offset a) by lia.
  induction a; cbn.
  trivial.
Qed.

Lemma shift_injective :
   forall a, forall i j, (shift a i) = (shift a j) -> i = j.
Proof.
  intros a i j EQ.

  cut (offset (shift a i) = offset (shift a j)).
  {
    intros H.
    unfold shift in H.
    cbn in H.
    lia.
  }
  {
    rewrite EQ; trivial.
  }
Qed.

Lemma shift_injective_neq :
   (forall a i j, i <> j -> (shift a i) <> (shift a j))%Z.
Proof.
   intros.
   intuition.
   apply H.
   apply shift_injective with (a); trivial.
Qed.

