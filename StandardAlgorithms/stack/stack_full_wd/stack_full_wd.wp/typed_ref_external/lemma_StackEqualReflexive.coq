(* ---------------------------------------------------------- *)
(* --- Lemma 'StackEqualReflexive'                        --- *)
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

(* --- Global Definitions   --- *)
Require Import Memory.

Definition L_Size (Mint_0 : farray addr Z) (s_0 : addr) : Z :=
    (Mint_0.[ (shift s_0 2%Z) ])%Z.

Definition L_Storage (Mptr_0 : farray addr addr) (s_0 : addr) : addr :=
    Mptr_0.[ (shift s_0 0%Z) ].

Definition P_EqualRanges_1_ (Mint_0 : farray addr Z) (Mint_1 : farray addr Z)
    (a_0 : addr) (n_0 : Z) (b_0 : addr) : Prop :=
    forall (i_0 : Z), ((i_0 < n_0)%Z) -> ((0 <= i_0)%Z) ->
      (((Mint_0.[ (shift b_0 i_0%Z) ]) = (Mint_1.[ (shift a_0 i_0%Z) ]))%Z)%Z.

Definition P_Equal (Mptr_0 : farray addr addr) (Mint_0 : farray addr Z)
    (Mptr_1 : farray addr addr) (Mint_1 : farray addr Z) (s_0 : addr)
    (t_0 : addr) : Prop :=
    let x_0 := ((L_Size Mint_1 s_0))%Z in
      ((x_0 = ((L_Size Mint_0 t_0)))%Z)%Z /\
      ((P_EqualRanges_1_ Mint_0 Mint_1 ((L_Storage Mptr_1 s_0)) x_0
         ((L_Storage Mptr_0 t_0)))).

Goal
  forall (Mint_0 : farray addr Z),
  forall (Mptr_0 : farray addr addr),
  forall (s_0 : addr),
  (P_Equal Mptr_0 Mint_0 Mptr_0 Mint_0 s_0 s_0).

