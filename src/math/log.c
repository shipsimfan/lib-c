#include <math.h>

#include "math.h"

#define LO __as_u64(1.0 - 0x1p-4)
#define HI __as_u64(1.0 + 0x1.09p-4)

#define OFF 0x3fe6000000000000
#define LOG_TABLE_BITS 7
#define N (1 << LOG_TABLE_BITS)
#define LN_2_HI 0x1.62e42fefa3800p-1
#define LN_2_LO 0x1.ef35793c76730p-45

u64 __as_u64(double x) {
    union {
        double d;
        u64 i;
    } u = {x};
    return u.i;
}

double __as_double(u64 i) {
    union {
        u64 i;
        double d;
    } u = {i};
    return u.d;
}

u32 __top_16(u64 x) { return x >> 48; }

double log(double x) {
#include "log_table.h"

    u64 ix = __as_u64(x);
    u32 top = __top_16(x);

    if (ix - LO < HI - LO) {
        // Handle values close to 1.0
        // Uses a taylor series expansion of ln(x) around 1
        if (ix == __as_u64(1.0))
            return 0.;

        double r = x - 1.0;
        double r2 = r * r;
        double r3 = r * r2;
        double y =
            r3 * (B[1] + r * B[2] + r2 * B[3] +
                  r3 * (B[4] + r * B[5] + r2 * B[6] +
                        r3 * (B[7] + r * B[8] + r2 * B[9] + r3 * B[10])));

        double w = r * 0x1p27;
        double rhi = r + w - w;
        double rlo = r - rhi;
        w = rhi * rhi * B[0];
        double hi = r + w;
        double lo = r - hi + w;
        lo += B[0] * rlo * (rhi + r);
        y += lo;
        y += hi;
        return y;
    }

    if (top - 0x0010 >= 0x7FF0 - 0x0010) {
        if (ix * 2 == 0)
            return __math_div_zero(1);
        if (ix == __as_u64(INFINITY))
            return x;
        if ((top & 0x8000) || (top & 0x7FF0) == 0x7FF0)
            return __math_invalid(x);

        ix = __as_u64(x * 0x1p52);
        ix -= 52ULL << 52;
    }

    u64 tmp = ix - OFF;
    int i = (tmp >> (52 - LOG_TABLE_BITS)) % N;
    int k = (i64)tmp >> 52;
    u64 iz = ix - (tmp & 0xFFFULL << 52);
    double invc = T[i].invc;
    double logc = T[i].logc;
    double z = __as_double(iz);

    double r = (z - T2[i].chi - T2[i].clo) * invc;

    double kd = (double)k;

    double w = kd * LN_2_HI + logc;
    double hi = w + r;
    double lo = w - hi + r + kd * LN_2_LO;

    double r2 = r * r;

    return lo + r2 * A[0] + r * r2 * (A[1] + r * A[2] + r2 * (A[3] + r * A[4]));
}