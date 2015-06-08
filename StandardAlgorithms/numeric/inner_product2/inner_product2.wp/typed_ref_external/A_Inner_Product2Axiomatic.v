(* ---------------------------------------------------------- *)
(* --- Axiomatic 'Inner_Product2Axiomatic'                --- *)
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

Parameter L_Inner_Product2 : farray addr Z -> addr -> addr -> Z -> Z -> Z.
Require Import Cint.

Require Import Compound.
Require Import A_AccumulateAxiomatic.

Hypothesis Q_Inner_Product2: forall (i_1 i : Z), forall (t : farray addr Z),
  forall (a_2 a_1 a : addr), ((is_sint32 i_1%Z)) ->
  (forall (i_2 : Z), ((i_2 < i)%Z) -> ((0 <= i_2)%Z) ->
   (((t.[ (shift_sint32 a i_2%Z) ])
     = ((t.[ (shift_sint32 a_1 i_2%Z) ]) * (t.[ (shift_sint32 a_2 i_2%Z) ])))%Z)%Z) ->
  ((((L_Accumulate_1_ t a i%Z i_1%Z))
    = ((L_Inner_Product2 t a_2 a_1 i%Z i_1%Z)))%Z)%Z.

