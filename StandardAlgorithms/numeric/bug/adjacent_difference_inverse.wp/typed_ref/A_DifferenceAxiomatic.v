(* ---------------------------------------------------------- *)
(* --- Axiomatic 'DifferenceAxiomatic'                    --- *)
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

Parameter L_Difference : farray addr Z -> addr -> Z -> Z.

Require Import Axiomatic.

Hypothesis Q_DifferenceRead: forall (i : Z), forall (t_1 t : farray addr Z),
  forall (a : addr), ((P_Unchanged_2_ t_1 t a (1%Z + i%Z)%Z)) ->
  ((((L_Difference t a i%Z)) = ((L_Difference t_1 a i%Z)))%Z).

Require Import Compound.

Hypothesis Q_DifferenceNext: forall (i : Z), forall (t : farray addr Z),
  forall (a : addr), ((0 < i)%Z) ->
  (((t.[ (shift_sint32 a i%Z) ])
    = (((L_Difference t a i%Z)) + (t.[ (shift_sint32 a (i%Z - 1%Z)%Z) ])))%Z).

Hypothesis Q_DifferenceEmptyOrSingle: forall (i : Z),
  forall (t : farray addr Z), forall (a : addr), ((i <= 0)%Z) ->
  ((((L_Difference t a i%Z)) = (t.[ (shift_sint32 a 0%Z) ]))%Z).
Require Import Cint.

Hypothesis Q_TL_Difference: forall (i : Z), forall (t : farray addr Z),
  forall (a : addr), (is_sint32 ((L_Difference t a i%Z))%Z).

