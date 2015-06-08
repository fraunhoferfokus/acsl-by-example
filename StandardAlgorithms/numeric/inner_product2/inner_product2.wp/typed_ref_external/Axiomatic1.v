(* ---------------------------------------------------------- *)
(* --- Global Definitions (continued #1)                  --- *)
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
Require Import Compound.

Definition P_EqualRanges_2_ (Mint_0 : farray addr Z) (Mint_1 : farray addr Z)
    (a : addr) (n : Z) : Prop :=
    forall (i : Z), let a_1 := (shift_sint32 a i%Z) in ((i < n)%Z) ->
      ((0 <= i)%Z) -> (((Mint_0.[ a_1 ]) = (Mint_1.[ a_1 ]))%Z)%Z.

