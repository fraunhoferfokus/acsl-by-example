
#include "random_number.h"

extern "C" long int lrand48(void);

size_type random_number(size_type n)
{
    return lrand48() % n;
}

