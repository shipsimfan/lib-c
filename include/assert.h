#ifndef __ASSERT_H
#define __ASSERT_H

#include <stdio.h>
#include <stdlib.h>

#define assert(expression)                                                     \
    if (expression != 0) {                                                     \
        fprintf(stderr, "Assertion expression failed");                        \
        abort();                                                               \
    }

#endif