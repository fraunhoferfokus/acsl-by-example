(* ---------------------------------------------------------- *)
(* --- Lemma 'PartialSum_Next'                            --- *)
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

(* --- Global Definitions (continued #3) --- *)

Require Import Axiomatic2.
Require Import Memory.
Require Import Compound.

Definition P_PartialSum (Mint_0 : farray addr Z) (Mint_1 : farray addr Z)
    (a : addr) (n : Z) (b : addr) : Prop :=
    forall (i : Z), ((i < n)%Z) -> ((0 <= i)%Z) ->
      (((Mint_0.[ (shift_sint32 b i%Z) ])
        = ((L_Accumulate_2_ Mint_1 a (1%Z + i%Z)%Z)))%Z)%Z.

Goal
  forall (i : Z),
  forall (t_1 t : farray addr Z),
  forall (a_1 a : addr),
  ((0 < i)%Z) ->
  ((P_PartialSum t_1 t a_1 i%Z a)) ->
  (((t_1.[ (shift_sint32 a i%Z) ])
    = ((t.[ (shift_sint32 a_1 i%Z) ])
       + (t_1.[ (shift_sint32 a (i%Z - 1%Z)%Z) ])))%Z)%Z ->
  ((P_PartialSum t_1 t a_1 (1%Z + i%Z)%Z a)).

