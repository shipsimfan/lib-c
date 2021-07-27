#include <stdlib.h>

div_t div(int numer, int denom) {
    div_t ret = {
        numer / denom,
        numer % denom,
    };

    return ret;
}