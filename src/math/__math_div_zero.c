#include "math.h"

#define math_opt_barrier(x)                                                    \
    ({                                                                         \
        __typeof(x) __x = (x);                                                 \
        __asm("" : "+m"(__x));                                                 \
        __x;                                                                   \
    })

double __math_div_zero(u32 sign) {
    return math_opt_barrier(sign ? -1.0 : 1.0) / 0.0;
}