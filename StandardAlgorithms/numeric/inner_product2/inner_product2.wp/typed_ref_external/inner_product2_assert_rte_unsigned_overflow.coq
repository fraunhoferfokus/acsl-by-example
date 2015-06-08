(* ---------------------------------------------------------- *)
(* --- Assertion 'rte,unsigned_overflow' (file inner_product2.c, line 6) --- *)
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

Require Import Axiomatic3.
Require Import Axiomatic2.
Require Import Memory.
Require Import Cint.
Require Import Compound.
Require Import A_Inner_Product2Axiomatic.

Goal
  forall (i_1 i : Z),
  forall (t : array Z),
  forall (t_1 : farray addr Z),
  forall (a_1 a : addr),
  let x := (4 * i)%Z in
  let x_1 := ((L_Inner_Product2 t_1 a a_1 i%Z i_1%Z))%Z in
  ((x <= 4294967295)%Z) ->
  ((linked t)) ->
  ((is_sint32 i_1%Z)) ->
  ((is_uint32 i%Z)) ->
  ((((region ((base a))%Z)) <= 0)%Z) ->
  ((((region ((base a_1))%Z)) <= 0)%Z) ->
  ((valid_rd t ((shift_sint32 a 0%Z)) i%Z)) ->
  ((valid_rd t ((shift_sint32 a_1 0%Z)) i%Z)) ->
  (forall (i_2 : Z), ((0 <= i_2)%Z) -> ((i_2 <= i)%Z) ->
   ((((-2147483648) <= x_1)%Z) /\ ((x_1 <= 2147483647)%Z))) ->
  (forall (i_2 : Z),
   let x_2 := ((t_1.[ (shift_sint32 a i_2%Z) ]) *
               (t_1.[ (shift_sint32 a_1 i_2%Z) ]))%Z in ((i_2 < i)%Z) ->
   ((0 <= i_2)%Z) -> ((((-2147483648) <= x_2)%Z) /\ ((x_2 <= 2147483647)%Z))) ->
  ((0 <= x)%Z).

