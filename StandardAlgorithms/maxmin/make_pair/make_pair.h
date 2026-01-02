
#ifndef MAKE_PAIR_H_INCLUDED
#define MAKE_PAIR_H_INCLUDED

#include "SizeTypePairTrivial.acsl"

/*@
    terminates         \true;
    exits              \false;
    assigns            \nothing;

    ensures   result:  \result.first  == first;
    ensures   result:  \result.second == second;
*/
size_type_pair
make_pair(size_type first, size_type second);

#endif /* MAKE_PAIR_H_INCLUDED */

