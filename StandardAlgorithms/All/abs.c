
// frama-c -wp -wp-rte -wp-prover why3 -wp-gen -wp-out abs.wp  abs.c

#include "abs.h"

int abs(int x)
{
  return (x >= 0) ? x : -x;
}

