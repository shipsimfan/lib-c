#include <stdlib.h>

ldiv_t ldiv(long int numer, long int denom) {
    ldiv_t ret = {
        numer / denom,
        numer % denom,
    };

    return ret;
}