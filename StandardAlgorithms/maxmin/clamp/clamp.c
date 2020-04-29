
#include "clamp.h"
#include "LessThanComparable.acsl"


value_type
clamp(value_type v, value_type lower, value_type upper)
{
  return (v < lower) ? lower : (upper < v) ? upper : v;
}

