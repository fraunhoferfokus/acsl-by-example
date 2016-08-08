(* ---------------------------------------------------------- *)
(* --- Lemma 'AdjacentDifferenceInverse'                  --- *)
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

(* --- Global Definitions (continued #2) --- *)
Require Import Memory.

Require Import A_DifferenceAxiomatic.
Require Import Compound.

Definition P_AdjacentDifference (Mint_0 : farray addr Z) (a : addr) (n : Z)
    (b : addr) : Prop :=
    forall (i : Z), ((i < n)%Z) -> ((0 <= i)%Z) ->
      ((((L_Difference Mint_0 a i%Z)) = (Mint_0.[ (shift_sint32 b i%Z) ]))%Z).

Hypothesis Q_AdjacentDifferenceSection: forall (i_1 i : Z),
  forall (t : farray addr Z), forall (a_1 a : addr), ((0 <= i_1)%Z) ->
  ((i_1 <= i)%Z) -> ((P_AdjacentDifference t a_1 i%Z a)) ->
  ((P_AdjacentDifference t a_1 i_1%Z a)).

Require Import Axiomatic.

Hypothesis Q_AdjacentDifferenceStep: forall (i : Z),
  forall (t_1 t : farray addr Z), forall (a_1 a : addr),
  let x := (1%Z + i%Z)%Z in
  ((((L_Difference t_1 a_1 i%Z)) = (t_1.[ (shift_sint32 a i%Z) ]))%Z) ->
  ((P_Unchanged_2_ t_1 t a i%Z)) -> ((P_AdjacentDifference t a_1 i%Z a)) ->
  ((P_Unchanged_2_ t_1 t a_1 x)) -> ((P_AdjacentDifference t_1 a_1 x a)).

Require Import Axiomatic1.

Hypothesis Q_PartialSumStep2: forall (i : Z), forall (t_1 t : farray addr Z),
  forall (a_1 a : addr), let x := (1%Z + i%Z)%Z in ((0 < i)%Z) ->
  ((P_Unchanged_2_ t_1 t a i%Z)) -> ((P_PartialSum t a_1 i%Z a)) ->
  (((t_1.[ (shift_sint32 a i%Z) ]) = ((L_Accumulate_2_ t_1 a_1 x)))%Z) ->
  ((P_Unchanged_2_ t_1 t a_1 x)) -> ((P_PartialSum t_1 a_1 x a)).

Hypothesis Q_PartialSumStep: forall (i : Z), forall (t : farray addr Z),
  forall (a_1 a : addr), let x := (1%Z + i%Z)%Z in ((0 < i)%Z) ->
  ((P_PartialSum t a_1 i%Z a)) ->
  (((t.[ (shift_sint32 a i%Z) ]) = ((L_Accumulate_2_ t a_1 x)))%Z) ->
  ((P_PartialSum t a_1 x a)).

Hypothesis Q_PartialSumUnchanged: forall (i : Z),
  forall (t_1 t : farray addr Z), forall (a_1 a : addr), ((0 <= i)%Z) ->
  ((P_Unchanged_2_ t_1 t a i%Z)) -> ((P_Unchanged_2_ t_1 t a_1 i%Z)) ->
  ((P_PartialSum t a_1 i%Z a)) -> ((P_PartialSum t_1 a_1 i%Z a)).

Hypothesis Q_PartialSumSection: forall (i_1 i : Z),
  forall (t : farray addr Z), forall (a_1 a : addr), ((0 <= i_1)%Z) ->
  ((i_1 <= i)%Z) -> ((P_PartialSum t a_1 i%Z a)) ->
  ((P_PartialSum t a_1 i_1%Z a)).

Hypothesis Q_UnchangedTransitive: forall (i : Z),
  forall (t_2 t_1 t : farray addr Z), forall (a : addr), ((0 <= i)%Z) ->
  ((P_Unchanged_2_ t_1 t a i%Z)) -> ((P_Unchanged_2_ t_2 t_1 a i%Z)) ->
  ((P_Unchanged_2_ t_2 t a i%Z)).

Goal
  forall (i : Z),
  forall (t_1 t : farray addr Z),
  forall (a_1 a : addr),
  ((0 <= i)%Z) ->
  ((P_Unchanged_2_ t_1 t a i%Z)) ->
  ((P_PartialSum t_1 a i%Z a_1)) ->
  ((P_AdjacentDifference t a_1 i%Z a)) ->
  ((P_Unchanged_2_ t_1 t a_1 i%Z)).

