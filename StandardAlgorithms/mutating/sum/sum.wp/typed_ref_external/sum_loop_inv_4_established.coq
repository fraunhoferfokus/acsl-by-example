(* ---------------------------------------------------------- *)
(* --- Establishment of Invariant (file sum.c, line 13)   --- *)
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
Require Import Cint.

Goal
  forall (i_0 n_0 : Z),
  forall (Malloc_0 : array Z),
  forall (Mint_1 Mint_0 : farray addr Z),
  forall (a_0 : addr),
  ((n_0 <= 4294967295)%Z) ->
  ((linked Malloc_0)) ->
  ((is_uint32 n_0%Z)) ->
  ((is_sint32 (Mint_1.[ (shift a_0 i_0%Z) ])%Z)) ->
  ((valid_rd Malloc_0 ((shift a_0 0%Z)) n_0%Z)) ->
  (forall (i_1 : Z), ((i_1 < n_0)%Z) -> ((0 <= i_1)%Z) ->
   ((0 <= (Mint_0.[ (shift a_0 i_1%Z) ]))%Z)) ->
  (forall (i_1 : Z), let x_0 := (n_0 * (Mint_0.[ (shift a_0 i_1%Z) ]))%Z in
   ((i_1 < n_0)%Z) -> ((0 <= i_1)%Z) ->
   (((0 <= x_0)%Z) /\ ((x_0 <= 2147483647)%Z))) ->
  ((0 <= (2147483647 * n_0))%Z).

