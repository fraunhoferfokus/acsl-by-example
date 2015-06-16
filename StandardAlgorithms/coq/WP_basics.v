
Require Import ZArith.
Require Import Memory.
Open Local Scope Z_scope.

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
  replace (offset a + 0) with (offset a) by auto with zarith.
  induction a.
  simpl.
  trivial.
Qed.

Lemma shift_injective :
   forall a, forall i j, (shift a i) = (shift a j) -> i = j.
Proof.
  intros a i j EQ.
  assert(offset (shift a i) = offset (shift a j)).
  rewrite EQ. trivial.
  unfold shift in H.
  simpl in H.
  auto with zarith.
Qed.

Lemma shift_injective_neq :
   (forall a i j, i <> j -> (shift a i) <> (shift a j))%Z.
Proof.
   intros.
   intuition.
   assert(offset (shift a i) = offset (shift a j)).
     rewrite H0.
     reflexivity.
   simpl in H1.
   auto with zarith.
Qed.

