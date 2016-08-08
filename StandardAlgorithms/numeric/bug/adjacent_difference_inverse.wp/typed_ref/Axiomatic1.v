(* ---------------------------------------------------------- *)
(* --- Global Definitions (continued #1)                  --- *)
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
Require Import A_AccumulateAxiomatic.

Definition L_Accumulate_2_ (Mint_0 : farray addr Z) (a : addr) (n : Z) : Z :=
    ((L_Accumulate_1_ Mint_0 a n%Z 0%Z))%Z.

Definition P_PartialSum (Mint_0 : farray addr Z) (a : addr) (n : Z)
    (b : addr) : Prop :=
    forall (i : Z), ((i < n)%Z) -> ((0 <= i)%Z) ->
      (((Mint_0.[ (shift_sint32 b i%Z) ])
        = ((L_Accumulate_2_ Mint_0 a (1%Z + i%Z)%Z)))%Z).

Require Import Axiomatic.

Hypothesis Q_AccumulateDefaultRead: forall (i : Z),
  forall (t_1 t : farray addr Z), forall (a : addr),
  ((P_Unchanged_2_ t_1 t a i%Z)) ->
  ((((L_Accumulate_2_ t a i%Z)) = ((L_Accumulate_2_ t_1 a i%Z)))%Z).

Hypothesis Q_AccumulateDefaultNext: forall (i : Z),
  forall (t : farray addr Z), forall (a : addr), ((0 <= i)%Z) ->
  ((((L_Accumulate_2_ t a (1%Z + i%Z)%Z))
    = (((L_Accumulate_2_ t a i%Z)) + (t.[ (shift_sint32 a i%Z) ])))%Z).

Hypothesis Q_AccumulateDefault1: forall (t : farray addr Z),
  forall (a : addr),
  (((L_Accumulate_2_ t a 1%Z)) = (t.[ (shift_sint32 a 0%Z) ]))%Z.

Hypothesis Q_AccumulateDefault0: forall (t : farray addr Z),
  forall (a : addr), (0 = ((L_Accumulate_2_ t a 0%Z)))%Z.
Require Import Cint.

Hypothesis Q_TL_Accumulate_2_: forall (i : Z), forall (t : farray addr Z),
  forall (a : addr), (is_sint32 ((L_Accumulate_2_ t a i%Z))%Z).

