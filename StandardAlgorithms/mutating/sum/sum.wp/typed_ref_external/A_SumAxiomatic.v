(* ---------------------------------------------------------- *)
(* --- Axiomatic 'SumAxiomatic'                           --- *)
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

Parameter L_Sum : farray addr Z -> addr -> Z -> Z.

Hypothesis Q_SumNext: forall (n_0 : Z), forall (Mint_0 : farray addr Z),
  forall (a_0 : addr),
  ((((L_Sum Mint_0 a_0 (1%Z + n_0%Z)%Z))
    = (((L_Sum Mint_0 a_0 n_0%Z)) + (Mint_0.[ (shift a_0 n_0%Z) ])))%Z)%Z.

Hypothesis Q_SumEmpty: forall (n_0 : Z), forall (Mint_0 : farray addr Z),
  forall (a_0 : addr), ((n_0 <= 0)%Z) ->
  ((0 = ((L_Sum Mint_0 a_0 n_0%Z)))%Z)%Z.

