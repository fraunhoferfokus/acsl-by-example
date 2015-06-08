(* ---------------------------------------------------------- *)
(* --- Lemma 'Accumulate_1'                               --- *)
(* ---------------------------------------------------------- *)
Require Import ZArith.
Require Import Reals.
Require Import BuiltIn.
Require Import bool.Bool.
Require Import int.Int.
Require Import int.Abs.
Require Import int.ComputerDivision.
Require Import real.Real.
Require Import real.RealInfix.
Require Import real.FromInt.
Require Import map.Map.
Require Import Qedlib.
Require Import Qed.
Require Import WP_basics.

(* --- Global Definitions (continued #2) --- *)
Require Import Memory.

Require Import A_AccumulateAxiomatic.

Definition L_Accumulate_2_ (Mint_0 : farray addr Z) (a : addr) (n : Z) : Z :=
    ((L_Accumulate_1_ Mint_0 a n%Z 0%Z))%Z.

Require Import Compound.

Goal
  forall (t : farray addr Z),
  forall (a : addr),
  ((((L_Accumulate_2_ t a 1%Z)) = (t.[ (shift_sint32 a 0%Z) ]))%Z)%Z.
