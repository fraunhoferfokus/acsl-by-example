(* ---------------------------------------------------------- *)
(* --- Post-condition (file stack_full_wd.c, line 11) in 'stack_full_wd' --- *)
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

Require Import Axiomatic.
Require Import Memory.
Require Import Cint.

Goal
  forall (stack_full_1 stack_full_0 : Z),
  forall (Malloc_0 : array Z),
  forall (Mint_0 : farray addr Z),
  forall (Mptr_0 : farray addr addr),
  forall (s_0 t_0 : addr),
  ((framed Mptr_0)) ->
  ((linked Malloc_0)) ->
  ((is_sint32 stack_full_1%Z)) ->
  ((is_sint32 stack_full_0%Z)) ->
  (((1 = stack_full_1)%Z)%Z <-> ((P_Full Mint_0 t_0))) ->
  (((1 = stack_full_0)%Z)%Z <-> ((P_Full Mint_0 s_0))) ->
  (((0 = stack_full_1)%Z)%Z <-> (~((P_Full Mint_0 t_0)))) ->
  (((0 = stack_full_0)%Z)%Z <-> (~((P_Full Mint_0 s_0)))) ->
  ((P_Valid Malloc_0 Mptr_0 Mint_0 s_0)) ->
  ((P_Valid Malloc_0 Mptr_0 Mint_0 t_0)) ->
  ((P_Equal Mptr_0 Mint_0 Mptr_0 Mint_0 s_0 t_0)) ->
  ((0 <> (if ((Zeq_bool stack_full_1 stack_full_0))%Z then 1 else 0))%Z)%Z.

