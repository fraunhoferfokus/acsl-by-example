(* ---------------------------------------------------------- *)
(* --- Axiomatic 'AccumulateAxiomatic'                    --- *)
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
Require Import Memory.

Parameter L_Accumulate_1_ : farray addr Z -> addr -> Z -> Z -> Z.
Require Import Cint.

Require Import Axiomatic1.

Hypothesis Q_AccumulateRead: forall (i_1 i : Z),
  forall (t_1 t : farray addr Z), forall (a : addr), ((is_sint32 i_1%Z)) ->
  ((P_EqualRanges_2_ t_1 t a i%Z)) ->
  ((((L_Accumulate_1_ t a i%Z i_1%Z))
    = ((L_Accumulate_1_ t_1 a i%Z i_1%Z)))%Z)%Z.

Require Import Compound.

Hypothesis Q_AccumulateNext: forall (i_1 i : Z), forall (t : farray addr Z),
  forall (a : addr), ((0 <= i)%Z) -> ((is_sint32 i_1%Z)) ->
  ((((L_Accumulate_1_ t a (1%Z + i%Z)%Z i_1%Z))
    = ((t.[ (shift_sint32 a i%Z) ]) + ((L_Accumulate_1_ t a i%Z i_1%Z))))%Z)%Z.

Hypothesis Q_AccumulateEmpty: forall (i_1 i : Z), forall (t : farray addr Z),
  forall (a : addr), ((i <= 0)%Z) -> ((is_sint32 i_1%Z)) ->
  ((i_1 = ((L_Accumulate_1_ t a i%Z i_1%Z)))%Z)%Z.

