#include <stdlib.h>

long int labs(long int x) {
    if (x < 0)
        return -x;
    else
        return x;
}