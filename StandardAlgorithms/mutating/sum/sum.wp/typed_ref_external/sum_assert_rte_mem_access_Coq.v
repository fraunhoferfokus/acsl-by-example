(* ---------------------------------------------------------- *)
(* --- Assertion 'rte,mem_access' (file sum.c, line 23)   --- *)
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

Require Import A_SumAxiomatic.

Goal
  forall (i_0 n_0 : Z),
  forall (Malloc_0 : array Z),
  forall (Mint_1 Mint_0 : farray addr Z),
  forall (a_0 : addr),
  let x_0 := ((L_Sum Mint_0 a_0 i_0%Z))%Z in
  let a_1 := (shift a_0 i_0%Z) in
  ((i_0 < n_0)%Z) ->
  ((0 <= i_0)%Z) ->
  ((i_0 <= n_0)%Z) ->
  ((linked Malloc_0)) ->
  ((is_uint32 i_0%Z)) ->
  ((is_uint32 n_0%Z)) ->
  (((-2147483648) <= x_0)%Z) ->
  ((x_0 <= 2147483647)%Z) ->
  ((is_sint32 x_0)) ->
  ((is_sint32 (Mint_1.[ a_1 ])%Z)) ->
  ((valid_rd Malloc_0 ((shift a_0 0%Z)) n_0%Z)) ->
  (forall (i_1 : Z), let x_1 := ((L_Sum Mint_0 a_0 i_1%Z))%Z in
   ((0 <= i_1)%Z) -> ((i_1 <= n_0)%Z) ->
   ((((-2147483648) <= x_1)%Z) /\ ((x_1 <= 2147483647)%Z))) ->
  ((valid_rd Malloc_0 a_1 1%Z)).

Proof.
  auto with zarith.
Qed.

