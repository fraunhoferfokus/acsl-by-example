
Require Import ZArith.
Require Import Memory.
Require Import Psatz.

Open Scope Z_scope.


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

