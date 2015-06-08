(* ---------------------------------------------------------- *)
(* --- Memory Compound Updates                            --- *)
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

Definition shift_sint32 (p : addr) (k : Z) : addr := (shift p k%Z).

