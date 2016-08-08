(* ---------------------------------------------------------- *)
(* --- Global Definitions                                 --- *)
(* ---------------------------------------------------------- *)

Require Import ZArith.
Require Import Reals.
Require Import BuiltIn.
Require Import int.Int.
Require Import int.Abs.
Require Import int.ComputerDivision.
Require Import real.Real.
Require Import real.RealInfix.
Require Import real.FromInt.
Require Import map.Map.
Require Import Qedlib.
Require Import Qed.
Require Import Memory.
Require Import Compound.

Definition P_Unchanged_1_ (Mint_0 : farray addr Z) (Mint_1 : farray addr Z)
    (a : addr) (first_0 : Z) (last_0 : Z) : Prop :=
    forall (i : Z), let a_1 := (shift_sint32 a i%Z) in ((i < last_0)%Z) ->
      ((first_0 <= i)%Z) -> (((Mint_0.[ a_1 ]) = (Mint_1.[ a_1 ]))%Z).

Definition P_Unchanged_2_ (Mint_0 : farray addr Z) (Mint_1 : farray addr Z)
    (a : addr) (n : Z) : Prop := (P_Unchanged_1_ Mint_0 Mint_1 a 0%Z n%Z).

Hypothesis Q_UnchangedStep: forall (i : Z), forall (t_1 t : farray addr Z),
  forall (a : addr), let a_1 := (shift_sint32 a i%Z) in ((0 <= i)%Z) ->
  (((t.[ a_1 ]) = (t_1.[ a_1 ]))%Z) -> ((P_Unchanged_2_ t_1 t a i%Z)) ->
  ((P_Unchanged_2_ t_1 t a (1%Z + i%Z)%Z)).

Hypothesis Q_UnchangedSection: forall (i_1 i : Z),
  forall (t_1 t : farray addr Z), forall (a : addr), ((0 <= i_1)%Z) ->
  ((i_1 <= i)%Z) -> ((P_Unchanged_2_ t_1 t a i%Z)) ->
  ((P_Unchanged_2_ t_1 t a i_1%Z)).

